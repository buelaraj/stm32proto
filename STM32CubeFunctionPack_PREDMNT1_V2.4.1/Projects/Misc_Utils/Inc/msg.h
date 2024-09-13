/**
  ******************************************************************************
  * @file    msg.h
  * @author  MCD Application Team
  * @brief   Trace message API.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MSG_H
#define MSG_H

#include <stdio.h>
#include <stdlib.h>
#include "PM_AWS_config.h"


#ifdef   ENABLE_IOT_INFO
#define MSG_INFO
#endif

#ifdef ENABLE_IOT_WARN
#define MSG_WARNING
#endif
#ifdef ENABLE_IOT_ERROR
#define MSG_ERROR
#endif

#ifdef ENABLE_IOT_DEBUG
#define MSG_DEBUG
#endif


/**
 * @brief Debug level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */
#ifdef MSG_DEBUG
#define msg_debug(...)    \
  {\
  PMAWS_PRINTF("DEBUG:   %s L#%d ", __func__, __LINE__);  \
  PMAWS_PRINTF(__VA_ARGS__); \
  }
#else
#define msg_debug(...)
#endif


/**
 * @brief Info level logging macro.
 *
 * Macro to expose desired log message.  Info messages do not include automatic function names and line numbers.
 */
#ifdef MSG_INFO
#define msg_info(...)    \
  {\
  PMAWS_PRINTF(__VA_ARGS__); \
  }
#else
#define msg_info(...)
#endif

/**
 * @brief Warn level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */
#ifdef MSG_WARNING
#define msg_warning(...)   \
  { \
  PMAWS_PRINTF("WARN:  %s L#%d ", __func__, __LINE__);  \
  PMAWS_PRINTF(__VA_ARGS__); \
  }
#else
#define msg_warning(...)
#endif

/**
 * @brief Error level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */
#ifdef MSG_ERROR
#define msg_error(...)  \
  { \
  PMAWS_PRINTF("ERROR: %s L#%d ", __func__, __LINE__); \
  PMAWS_PRINTF(__VA_ARGS__); \
  }
#else
#define msg_error(...)
#endif

#endif /* MSG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
