################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/abinaya.LDAP/Downloads/en.fp-ind-predmnt1/STM32CubeFunctionPack_PREDMNT1_V2.4.1/Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gap_aci.c \
C:/Users/abinaya.LDAP/Downloads/en.fp-ind-predmnt1/STM32CubeFunctionPack_PREDMNT1_V2.4.1/Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gatt_aci.c \
C:/Users/abinaya.LDAP/Downloads/en.fp-ind-predmnt1/STM32CubeFunctionPack_PREDMNT1_V2.4.1/Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_hal_aci.c \
C:/Users/abinaya.LDAP/Downloads/en.fp-ind-predmnt1/STM32CubeFunctionPack_PREDMNT1_V2.4.1/Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_l2cap_aci.c 

OBJS += \
./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gap_aci.o \
./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gatt_aci.o \
./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_hal_aci.o \
./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_l2cap_aci.o 

C_DEPS += \
./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gap_aci.d \
./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gatt_aci.d \
./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_hal_aci.d \
./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_l2cap_aci.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gap_aci.o: C:/Users/abinaya.LDAP/Downloads/en.fp-ind-predmnt1/STM32CubeFunctionPack_PREDMNT1_V2.4.1/Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gap_aci.c Middlewares/BlueNRG-2/HCI/Controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L4R9xx -DUSE_HAL_DRIVER -DBLUENRG1_NWK_COPROC -DSPI_INTERFACE -DARM_MATH_CM4 -c -I../../../Inc -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../Drivers/BSP/Components/lps22hh -I../../../../../../../Drivers/BSP/STWIN -I../../../../../../../Drivers/BSP/Components/ism330dhcx -I../../../../../../../Drivers/BSP/Components/iis2mdc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/BlueNRG-2/includes -I../../../../../../../Middlewares/ST/BlueNRG-2/utils -I../../../../../../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../../../../../../Middlewares/ST/STM32_BLE_Manager/Inc -I../../../../../../../Middlewares/ST/STM32_MetaDataManager -I../../../../../../../Middlewares/ST/STM32_MotionSP_Library/Inc -I../../../../../../../Middlewares/Third_Party/parson -I../../../Patch -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gatt_aci.o: C:/Users/abinaya.LDAP/Downloads/en.fp-ind-predmnt1/STM32CubeFunctionPack_PREDMNT1_V2.4.1/Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_gatt_aci.c Middlewares/BlueNRG-2/HCI/Controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L4R9xx -DUSE_HAL_DRIVER -DBLUENRG1_NWK_COPROC -DSPI_INTERFACE -DARM_MATH_CM4 -c -I../../../Inc -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../Drivers/BSP/Components/lps22hh -I../../../../../../../Drivers/BSP/STWIN -I../../../../../../../Drivers/BSP/Components/ism330dhcx -I../../../../../../../Drivers/BSP/Components/iis2mdc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/BlueNRG-2/includes -I../../../../../../../Middlewares/ST/BlueNRG-2/utils -I../../../../../../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../../../../../../Middlewares/ST/STM32_BLE_Manager/Inc -I../../../../../../../Middlewares/ST/STM32_MetaDataManager -I../../../../../../../Middlewares/ST/STM32_MotionSP_Library/Inc -I../../../../../../../Middlewares/Third_Party/parson -I../../../Patch -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_hal_aci.o: C:/Users/abinaya.LDAP/Downloads/en.fp-ind-predmnt1/STM32CubeFunctionPack_PREDMNT1_V2.4.1/Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_hal_aci.c Middlewares/BlueNRG-2/HCI/Controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L4R9xx -DUSE_HAL_DRIVER -DBLUENRG1_NWK_COPROC -DSPI_INTERFACE -DARM_MATH_CM4 -c -I../../../Inc -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../Drivers/BSP/Components/lps22hh -I../../../../../../../Drivers/BSP/STWIN -I../../../../../../../Drivers/BSP/Components/ism330dhcx -I../../../../../../../Drivers/BSP/Components/iis2mdc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/BlueNRG-2/includes -I../../../../../../../Middlewares/ST/BlueNRG-2/utils -I../../../../../../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../../../../../../Middlewares/ST/STM32_BLE_Manager/Inc -I../../../../../../../Middlewares/ST/STM32_MetaDataManager -I../../../../../../../Middlewares/ST/STM32_MotionSP_Library/Inc -I../../../../../../../Middlewares/Third_Party/parson -I../../../Patch -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_l2cap_aci.o: C:/Users/abinaya.LDAP/Downloads/en.fp-ind-predmnt1/STM32CubeFunctionPack_PREDMNT1_V2.4.1/Middlewares/ST/BlueNRG-2/hci/controller/bluenrg1_l2cap_aci.c Middlewares/BlueNRG-2/HCI/Controller/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L4R9xx -DUSE_HAL_DRIVER -DBLUENRG1_NWK_COPROC -DSPI_INTERFACE -DARM_MATH_CM4 -c -I../../../Inc -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../Drivers/BSP/Components/lps22hh -I../../../../../../../Drivers/BSP/STWIN -I../../../../../../../Drivers/BSP/Components/ism330dhcx -I../../../../../../../Drivers/BSP/Components/iis2mdc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/BlueNRG-2/includes -I../../../../../../../Middlewares/ST/BlueNRG-2/utils -I../../../../../../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../../../../../../Middlewares/ST/STM32_BLE_Manager/Inc -I../../../../../../../Middlewares/ST/STM32_MetaDataManager -I../../../../../../../Middlewares/ST/STM32_MotionSP_Library/Inc -I../../../../../../../Middlewares/Third_Party/parson -I../../../Patch -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-BlueNRG-2d-2-2f-HCI-2f-Controller

clean-Middlewares-2f-BlueNRG-2d-2-2f-HCI-2f-Controller:
	-$(RM) ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gap_aci.d ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gap_aci.o ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gap_aci.su ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gatt_aci.d ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gatt_aci.o ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_gatt_aci.su ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_hal_aci.d ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_hal_aci.o ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_hal_aci.su ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_l2cap_aci.d ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_l2cap_aci.o ./Middlewares/BlueNRG-2/HCI/Controller/bluenrg1_l2cap_aci.su

.PHONY: clean-Middlewares-2f-BlueNRG-2d-2-2f-HCI-2f-Controller

