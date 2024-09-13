/**
  ******************************************************************************
  * @file    BLE_FFT_Amplitude.c
  * @author  System Research & Applications Team - Agrate/Catania Lab.
  * @version V0.3.0
  * @date    18-Jan-2021
  * @brief   Add BLE FFT amplitude info services using vendor specific profiles.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0094, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0094
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "BLE_Manager.h"
#include "BLE_ManagerCommon.h"

/* Private define ------------------------------------------------------------*/
#define COPY_FFT_AMPLITUDE_CHAR_UUID(uuid_struct) COPY_UUID_128(uuid_struct,0x00,0x00,0x00,0x05,0x00,0x02,0x11,0xe1,0xac,0x36,0x00,0x02,0xa5,0xd5,0xc5,0x1b)

#define FFT_AMPLITUDE_ADVERTIZE_DATA_POSITION  18

/* Exported variables --------------------------------------------------------*/
/* Identifies the notification Events */
BLE_NotifyEnv_t BLE_FFT_Amplitude_NotifyEvent = BLE_NOTIFY_NOTHING;

/* Private variables ---------------------------------------------------------*/
/* Data structure pointer for FFT Amplitude info service */
static BleCharTypeDef BleCharFFTAmplitude;

/* Private functions ---------------------------------------------------------*/
static void AttrMod_Request_FFTAmplitude(void *BleCharPointer,uint16_t attr_handle, uint16_t Offset, uint8_t data_length, uint8_t *att_data);

/**
 * @brief  Init FFT Amplitude info service
 * @param  None
 * @retval BleCharTypeDef* BleCharPointer: Data structure pointer for FFT Amplitude info service
 */
BleCharTypeDef* BLE_InitFFTAmplitudeService(void)
{
  /* Data structure pointer for BLE service */
  BleCharTypeDef *BleCharPointer;

  /* Init data structure pointer for FFT Amplitude info service */
  BleCharPointer = &BleCharFFTAmplitude;
  memset(BleCharPointer,0,sizeof(BleCharTypeDef));  
  BleCharPointer->AttrMod_Request_CB = AttrMod_Request_FFTAmplitude;
  COPY_FFT_AMPLITUDE_CHAR_UUID((BleCharPointer->uuid));
  BleCharPointer->Char_UUID_Type =UUID_TYPE_128;
  BleCharPointer->Char_Value_Length=20;
  BleCharPointer->Char_Properties=CHAR_PROP_NOTIFY;
  BleCharPointer->Security_Permissions=ATTR_PERMISSION_NONE;
  BleCharPointer->GATT_Evt_Mask=GATT_NOTIFY_READ_REQ_AND_WAIT_FOR_APPL_RESP;
  BleCharPointer->Enc_Key_Size=16;
  BleCharPointer->Is_Variable=1;

  BLE_MANAGER_PRINTF("BLE FFT Amplitude features ok\r\n");
  
  return BleCharPointer;
}

#ifndef BLE_MANAGER_SDKV2
/**
 * @brief  Setting FFT Amplitude Advertize Data
 * @param  uint8_t *manuf_data: Advertize Data
 * @retval None
 */
void BLE_SetFFTAmplitudeAdvertizeData(uint8_t *manuf_data)
{
  /* Setting FFT Amplitude Advertize Data */
 manuf_data[FFT_AMPLITUDE_ADVERTIZE_DATA_POSITION] |= 0x05U;
}
#endif /* BLE_MANAGER_SDKV2 */

extern sAccMagResults_t AccMagResults;
typedef struct
{
	float X;
	float Y;
	float Z;
} stddev_t;

typedef struct {
    float rms_x;
    float rms_y;
    float rms_z;
} RMSResults_t;

void MotionSP_fftStdDevFinding(sAccMagResults_t *pAccMagResults, stddev_t *std)
{
  uint16_t size = pAccMagResults->MagSizeTBU;

  arm_std_f32(pAccMagResults->Array.X, size, &std->X);
  arm_std_f32(pAccMagResults->Array.Y, size, &std->Y);
  arm_std_f32(pAccMagResults->Array.Z, size, &std->Z);
}

static void MotionSP_fftRMSfinding(sAccMagResults_t *pSrc, RMSResults_t *rmsResults)
{
    SensorVal_f_t SquareData = {0, 0, 0};
    SensorVal_f_t PrevSquareData = {0, 0, 0};
    static float WN = 0.0f;
    static float WN_1 = 0.0f;
    size_t samples = pSrc->MagSize;


    // Initialize WN if this is the first call
    if (WN == 0.0f) {
        WN = 1.0f;
    }

    for (size_t s = 0; s < samples; s++)
    {
        if (s == 0)
        {
            SquareData.AXIS_X = pSrc->Array.X[s] * pSrc->Array.X[s];
            SquareData.AXIS_Y = pSrc->Array.Y[s] * pSrc->Array.Y[s];
            SquareData.AXIS_Z = pSrc->Array.Z[s] * pSrc->Array.Z[s];
            PrevSquareData.AXIS_X = SquareData.AXIS_X;
            PrevSquareData.AXIS_Y = SquareData.AXIS_Y;
            PrevSquareData.AXIS_Z = SquareData.AXIS_Z;
        }
        else
        {
            SquareData.AXIS_X = pSrc->Array.X[s] * pSrc->Array.X[s];
            SquareData.AXIS_Y = pSrc->Array.Y[s] * pSrc->Array.Y[s];
            SquareData.AXIS_Z = pSrc->Array.Z[s] * pSrc->Array.Z[s];

            PrevSquareData.AXIS_X = pSrc->Array.X[s - 1] * pSrc->Array.X[s - 1];
            PrevSquareData.AXIS_Y = pSrc->Array.Y[s - 1] * pSrc->Array.Y[s - 1];
            PrevSquareData.AXIS_Z = pSrc->Array.Z[s - 1] * pSrc->Array.Z[s - 1];
        }

        // Compute RMS for each axis
        arm_sqrt_f32(((1 - 1 / WN) * PrevSquareData.AXIS_X + (1 / WN) * SquareData.AXIS_X), &rmsResults->rms_x);
        arm_sqrt_f32(((1 - 1 / WN) * PrevSquareData.AXIS_Y + (1 / WN) * SquareData.AXIS_Y), &rmsResults->rms_y);
        arm_sqrt_f32(((1 - 1 / WN) * PrevSquareData.AXIS_Z + (1 / WN) * SquareData.AXIS_Z), &rmsResults->rms_z);

        WN_1 = WN;
        WN = 5 * WN_1 + 1;
    }
}

/*
 * @brief  Update FFT Amplitude characteristic value
 * @param  uint8_t *DataToSend:
 *                  - 2 bytes for number of samples
 *                  - 1 byte for number of components (up to 3 components)
 *                  - 4 bytes for frequency steps
 *                  - 4 bytes for each component
 *                     (if number of components is more 1, for example 3, send the data in this format: X1,X2,X3,...Xn,Y1,Y2,Y3,...Yn,X1,Z2,Z3,...Zn)
 * @param  uint16_t DataNumber Number of samples
 * @param  uint8_t *SendingFFT
 * @param  uint16_t *CountSendData
 * @retval tBleStatus   Status
 */

tBleStatus BLE_FFTAmplitudeUpdate(uint8_t *DataToSend, uint16_t DataNumber, uint8_t *SendingFFT, uint16_t *CountSendData)
{
    tBleStatus ret;
    uint16_t TotalSize;
    uint16_t indexStart;
    uint16_t indexStop;
    uint16_t NumByteSent;

    // To find the FFT peak-value
    MotionSP_fftPeakFinding(&AccMagResults);
    float x_pval = AccMagResults.Max.X.value;
    float y_pval = AccMagResults.Max.Y.value;
    float z_pval = AccMagResults.Max.Z.value;

    // To find the FFT mean-value
    RMSResults_t fft_rms = {0};
    MotionSP_fftRMSfinding(&AccMagResults, &fft_rms);
    float x_rms = fft_rms.rms_x;
    float y_rms = fft_rms.rms_y;
    float z_rms = fft_rms.rms_z;

    // To find the std-dev
    stddev_t std = {0};
    MotionSP_fftStdDevFinding(&AccMagResults, &std);
    float x_std = std.X;
    float y_std = std.Y;
    float z_std = std.Z;

    // Create JSON string with sufficient size for all values
    char json_buffer[512]; // Adjust size if needed
    int length = snprintf(json_buffer, sizeof(json_buffer),
        "{"
        "\"time\": 12345678,"
        "\"edgeId\": \"dh000000\","
        "\"x\": {"
        "\"dur\": 0,"
        "\"mval\": %.3f,"
        "\"pval\": %.3f,"
        "\"stdev\": %.3f,"
        "\"out\": 0"
        "},"
        "\"y\": {"
        "\"dur\": 0,"
        "\"mval\": %.3f,"
        "\"pval\": %.3f,"
        "\"stdev\": %.3f,"
        "\"out\": 0"
        "},"
        "\"z\": {"
        "\"dur\": 0,"
        "\"mval\": %.3f,"
        "\"pval\": %.3f,"
        "\"stdev\": %.3f,"
        "\"out\": 0"
        "},"
        "\"vec\": {"
        "\"mag\": 135078900,"
        "\"dir\": 47"
        "}"
        "}",
        x_rms, x_pval, x_std,
        y_rms, y_pval, y_std,
        z_rms, z_pval, z_std);

    if (length < 0 || length >= sizeof(json_buffer)) {
        // Handle snprintf error or buffer too small case
        return BLE_STATUS_ERROR;
    }

    // Calculate total size of the JSON buffer
    TotalSize = length; // Use the length from snprintf

    // Determine start and stop indices for the current chunk of data
    indexStart = 20U * (*CountSendData);
    indexStop = 20U * ((*CountSendData) + 1U);

    // Adjust if indexStop exceeds TotalSize
    if (indexStop > TotalSize) {
        indexStop = TotalSize;
    }
    NumByteSent = (uint8_t)(indexStop - indexStart);

    // Send the JSON data to BLE
    ret = ACI_GATT_UPDATE_CHAR_VALUE(&BleCharFFTAmplitude, 0, NumByteSent, (uint8_t*)(json_buffer + indexStart));

    if (ret == BLE_STATUS_SUCCESS) {
        (*CountSendData)++;

        if (indexStop == TotalSize) {
            *SendingFFT = 0;
            *CountSendData = 0;
        }
    }

    return ret;
}



/**
 * @brief  This function is called when there is a change on the gatt attribute
 *         With this function it's possible to understand if FFT Amplitude is subscribed or not to the one service
 * @param  void *VoidCharPointer
 * @param  uint16_t attr_handle Handle of the attribute
 * @param  uint16_t Offset: (SoC mode) the offset is never used and it is always 0. Network coprocessor mode: 
 *                          - Bits 0-14: offset of the reported value inside the attribute.
 *                          - Bit 15: if the entire value of the attribute does not fit inside a single ACI_GATT_ATTRIBUTE_MODIFIED_EVENT event,
 *                            this bit is set to 1 to notify that other ACI_GATT_ATTRIBUTE_MODIFIED_EVENT events will follow to report the remaining value.                  
 * @param  uint8_t data_length length of the data
 * @param  uint8_t *att_data attribute data
 * @retval None
 */
static void AttrMod_Request_FFTAmplitude(void *VoidCharPointer, uint16_t attr_handle, uint16_t Offset, uint8_t data_length, uint8_t *att_data)
{
  if (att_data[0] == 01U) {
    BLE_FFT_Amplitude_NotifyEvent= BLE_NOTIFY_SUB;
  } else if (att_data[0] == 0U){
    BLE_FFT_Amplitude_NotifyEvent= BLE_NOTIFY_UNSUB;
 }
 
#if (BLE_DEBUG_LEVEL>1)
 if(BLE_StdTerm_Service==BLE_SERV_ENABLE) {
   BytesToWrite = (uint8_t)sprintf((char *)BufferToWrite,"--->FFT Amplitude=%s\n", (BLE_FFT_Amplitude_NotifyEvent == BLE_NOTIFY_SUB) ? " ON" : " OFF");
   Term_Update(BufferToWrite,BytesToWrite);
 } else {
   BLE_MANAGER_PRINTF("--->FFT Amplitude=%s", (BLE_FFT_Amplitude_NotifyEvent == BLE_NOTIFY_SUB) ? " ON\r\n" : " OFF\r\n");
 }
#endif
}

/******************* (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
