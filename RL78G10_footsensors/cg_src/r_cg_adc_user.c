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
* File Name    : r_cg_adc_user.c
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements device driver for ADC module.
* Creation Date: 2020/04/03
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_adc.h"
/* Start user code for include. Do not edit comment generated here */
#include <string.h>
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_adc_interrupt(vect=INTAD)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
volatile uint16_t	g_adc_data[D_ADC_NUM_CH] = {0};

static	uint16_t	s_adc_buf[D_ADC_NUM_CH][D_ADC_AVE] = {0};
static	uint8_t		s_adc_ptr = 0;

static
void	r_adc_average(
	uint8_t		ch
)
{
	uint16_u	t_adc;

	t_adc.b[1]	= ADCRH;
	t_adc.b[0]	= ADCRL;
	t_adc.u >>= 6;
	g_adc_data[ch] -=  s_adc_buf[ch][s_adc_ptr];
	g_adc_data[ch] += (s_adc_buf[ch][s_adc_ptr] = t_adc.u);
}

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_adc_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_adc_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	switch(ADS)
	{
	case 1:		r_adc_average(0);	ADS = 2;	break;
	case 2:		r_adc_average(1);	ADS = 3;	break;
	case 3:		r_adc_average(2);	ADS = 4;	break;
	case 4:		r_adc_average(3);	ADS = 1;
		//
		s_adc_ptr++;
		s_adc_ptr &= (D_ADC_AVE - 1);
		break;
	default:
		s_adc_ptr = 0;
		memset((void *)&g_adc_data[0],   0, sizeof(uint16_t) * D_ADC_NUM_CH);
		memset((void *)&s_adc_buf[0][0], 0, sizeof(uint16_t) * D_ADC_NUM_CH * D_ADC_AVE);
		ADS = 1;
		break;
	}
	ADCS = 1U;			/* enable AD conversion */

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
