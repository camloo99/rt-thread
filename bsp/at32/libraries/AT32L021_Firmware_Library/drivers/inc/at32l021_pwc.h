/**
  **************************************************************************
  * @file     at32l021_pwc.h
  * @brief    at32l021 pwc header file
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __AT32L021_PWC_H
#define __AT32L021_PWC_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "at32l021.h"

/** @addtogroup AT32L021_periph_driver
  * @{
  */

/** @addtogroup PWC
  * @{
  */

/** @defgroup PWC_flags_definition
  * @brief pwc flag
  * @{
  */

#define PWC_WAKEUP_FLAG                  ((uint32_t)0x00000001) /*!< wakeup flag */
#define PWC_STANDBY_FLAG                 ((uint32_t)0x00000002) /*!< standby flag */
#define PWC_PVM_OUTPUT_FLAG              ((uint32_t)0x00000004) /*!< pvm output flag */

/**
  * @}
  */

/**
  * @brief pwc wakeup pin num definition
  */
#define PWC_WAKEUP_PIN_1                 ((uint32_t)0x00000100) /*!< standby wake-up pin1(pa0) */
#define PWC_WAKEUP_PIN_2                 ((uint32_t)0x00000200) /*!< standby wake-up pin2(pc13) */
#define PWC_WAKEUP_PIN_4                 ((uint32_t)0x00000800) /*!< standby wake-up pin4(pa2) */
#define PWC_WAKEUP_PIN_6                 ((uint32_t)0x00002000) /*!< standby wake-up pin6(pb5) */
#define PWC_WAKEUP_PIN_7                 ((uint32_t)0x00004000) /*!< standby wake-up pin7(pb15) */

/**
  * @brief  select ldo output voltage.
  * @param  val: set the ldo output voltage.
  *         this parameter can be one of the following values:
  *         - PWC_LDO_OUTPUT_1V0: system clock up to 32MHz.
  *         - PWC_LDO_OUTPUT_1V2: system clock up to 80MHz.
  * @note   none.
  */
#define pwc_ldo_output_voltage_set(val)  (PWC->ctrl_bit.ldoovsel = val)

/** @defgroup PWC_exported_types
  * @{
  */

/**
  * @brief pwc pvm voltage type
  */
typedef enum
{
  PWC_PVM_VOLTAGE_2V15                   = 0x00, /*!< power voltage monitoring boundary 2.15v */
  PWC_PVM_VOLTAGE_2V30                   = 0x01, /*!< power voltage monitoring boundary 2.30v */
  PWC_PVM_VOLTAGE_2V45                   = 0x02, /*!< power voltage monitoring boundary 2.45v */
  PWC_PVM_VOLTAGE_2V60                   = 0x03, /*!< power voltage monitoring boundary 2.60v */
  PWC_PVM_VOLTAGE_2V75                   = 0x04, /*!< power voltage monitoring boundary 2.75v */
  PWC_PVM_VOLTAGE_2V90                   = 0x05, /*!< power voltage monitoring boundary 2.90v */
  PWC_PVM_VOLTAGE_3V00                   = 0x06  /*!< power voltage monitoring boundary 3.00v */
} pwc_pvm_voltage_type;

/**
  * @brief pwc ldo output voltage type
  */
typedef enum
{
  PWC_LDO_OUTPUT_1V0                     = 0x00, /*!< ldo output voltage is 1.0v */
  PWC_LDO_OUTPUT_1V2                     = 0x01  /*!< ldo output voltage is 1.2v */
} pwc_ldo_output_voltage_type;

/**
  * @brief pwc sleep enter type
  */
typedef enum
{
  PWC_SLEEP_ENTER_WFI                    = 0x00, /*!< use wfi enter sleep mode */
  PWC_SLEEP_ENTER_WFE                    = 0x01  /*!< use wfe enter sleep mode */
} pwc_sleep_enter_type;

/**
  * @brief pwc deep sleep enter type
  */
typedef enum
{
  PWC_DEEP_SLEEP_ENTER_WFI               = 0x00, /*!< use wfi enter deepsleep mode */
  PWC_DEEP_SLEEP_ENTER_WFE               = 0x01  /*!< use wfe enter deepsleep mode */
} pwc_deep_sleep_enter_type;

/**
  * @brief pwc regulator type
  */
typedef enum
{
  PWC_REGULATOR_ON                       = 0x00, /*!< voltage regulator state on when deepsleep mode */
  PWC_REGULATOR_LOW_POWER                = 0x01  /*!< voltage regulator state low power when deepsleep mode */
} pwc_regulator_type;

/**
  * @brief type define pwc register all
  */
typedef struct
{
  /**
    * @brief pwc ctrl register, offset:0x00
    */
  union
  {
    __IO uint32_t ctrl;
    struct
    {
      __IO uint32_t reserved1            : 1; /* [0] */
      __IO uint32_t lpsel                : 1; /* [1] */
      __IO uint32_t clswef               : 1; /* [2] */
      __IO uint32_t clsef                : 1; /* [3] */
      __IO uint32_t pvmen                : 1; /* [4] */
      __IO uint32_t pvmsel               : 3; /* [7:5] */
      __IO uint32_t bpwen                : 1; /* [8] */
      __IO uint32_t reserved2            : 3; /* [11:9] */
      __IO uint32_t vrlpen               : 1; /* [12] */
      __IO uint32_t reserved3            : 2; /* [14:13] */
      __IO uint32_t ldoovsel             : 1; /* [15] */
      __IO uint32_t reserved4            : 16;/* [31:16] */
    } ctrl_bit;
  };

  /**
    * @brief pwc ctrlsts register, offset:0x04
    */
  union
  {
    __IO uint32_t ctrlsts;
    struct
    {
      __IO uint32_t swef                 : 1; /* [0] */
      __IO uint32_t sef                  : 1; /* [1] */
      __IO uint32_t pvmof                : 1; /* [2] */
      __IO uint32_t reserved1            : 5; /* [7:3] */
      __IO uint32_t swpen1               : 1; /* [8] */
      __IO uint32_t swpen2               : 1; /* [9] */
      __IO uint32_t reserved2            : 1; /* [10] */
      __IO uint32_t swpen4               : 1; /* [11] */
      __IO uint32_t reserved3            : 1; /* [12] */
      __IO uint32_t swpen6               : 1; /* [13] */
      __IO uint32_t swpen7               : 1; /* [14] */
      __IO uint32_t reserved4            : 17;/* [31:15] */
    } ctrlsts_bit;
  };
} pwc_type;

/**
  * @}
  */

#define PWC                              ((pwc_type *) PWC_BASE)

/** @defgroup PWC_exported_functions
  * @{
  */

void pwc_reset(void);
void pwc_battery_powered_domain_access(confirm_state new_state);
void pwc_pvm_level_select(pwc_pvm_voltage_type pvm_voltage);
void pwc_power_voltage_monitor_enable(confirm_state new_state);
void pwc_wakeup_pin_enable(uint32_t pin_num, confirm_state new_state);
void pwc_flag_clear(uint32_t pwc_flag);
flag_status pwc_flag_get(uint32_t pwc_flag);
void pwc_sleep_mode_enter(pwc_sleep_enter_type pwc_sleep_enter);
void pwc_deep_sleep_mode_enter(pwc_deep_sleep_enter_type pwc_deep_sleep_enter);
void pwc_voltage_regulate_set(pwc_regulator_type pwc_regulator);
void pwc_standby_mode_enter(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
