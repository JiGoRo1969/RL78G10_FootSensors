/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012, 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_adc.h
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements device driver for ADC module.
* Creation Date: 2020/04/03
***********************************************************************************************************************/
#ifndef ADC_H
#define ADC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral enable register 0 (PER0)
*/
/* Control of AD converter input clock (ADCEN) */
#define _00_AD_CLOCK_STOP               (0x00U) /* stop supply of input clock */
#define _20_AD_CLOCK_SUPPLY             (0x20U) /* supply input clock */

/*
    AD converter mode register 0 (ADM0)
*/
#define _00_AD_ADM0_INITIALVALUE        (0x00U)
/* AD conversion operation control (ADCS) */
#define _80_AD_CONVERSION_ENABLE        (0x80U) /* enable AD conversion operation control */
#define _00_AD_CONVERSION_DISABLE       (0x00U) /* disable AD conversion operation control */
/* AD conversion clock selection (FR1, FR0) */
#define _00_AD_CONVERSION_CLOCK_8       (0x00U) /* fCLK/8 */
#define _08_AD_CONVERSION_CLOCK_4       (0x08U) /* fCLK/4 */
#define _10_AD_CONVERSION_CLOCK_2       (0x10U) /* fCLK/2 */
#define _18_AD_CONVERSION_CLOCK_1       (0x18U) /* fCLK/1 */
/* Specification AD conversion time mode (LV0) */
#define _00_AD_TIME_MODE_NORMAL_1       (0x00U) /* normal 1 mode */
#define _02_AD_TIME_MODE_NORMAL_2       (0x02U) /* normal 2 mode */
/* AD comparator operation control (ADCE) */
#define _01_AD_COMPARATOR_ENABLE        (0x01U) /* enable comparator operation control */
#define _00_AD_COMPARATOR_DISABLE       (0x00U) /* disable comparator operation control */

/*
    Analog input channel specification register (ADS)
*/
/* Specification of analog input channel (ADS2 - ADS0) */
/* Select mode */
#define _00_AD_INPUT_CHANNEL_0          (0x00U) /* ANI0 */
#define _01_AD_INPUT_CHANNEL_1          (0x01U) /* ANI1 */
#define _02_AD_INPUT_CHANNEL_2          (0x02U) /* ANI2 */
#define _03_AD_INPUT_CHANNEL_3          (0x03U) /* ANI3 */
#define _04_AD_INPUT_CHANNEL_4          (0x04U) /* ANI4 */
#define _05_AD_INPUT_CHANNEL_5          (0x05U) /* ANI5 */
#define _06_AD_INPUT_CHANNEL_6          (0x06U) /* ANI6 */
#define _07_AD_INPUT_INTERREFVOLT       (0x07U) /* internal reference voltage output */

/*
    AD converter mode register 2 (ADM2)
*/
/* AD resolution selection (ADTYP) */
#define _00_AD_RESOLUTION_10BIT         (0x00U) /* 10 bits */
#define _01_AD_RESOLUTION_8BIT          (0x01U) /* 8 bits */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    ADCHANNEL0,
    ADCHANNEL1,
    ADCHANNEL2,
    ADCHANNEL3,
    ADCHANNEL4,
    ADCHANNEL5,
    ADCHANNEL6,
    ADINTERREFVOLT
} ad_channel_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_ADC_Create(void);
void R_ADC_Start(void);
void R_ADC_Stop(void);
void R_ADC_Set_OperationOn(void);
void R_ADC_Set_OperationOff(void);
void R_ADC_Get_Result(uint16_t * const buffer);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
