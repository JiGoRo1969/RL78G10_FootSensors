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
* File Name    : r_cg_main.c
* Version      : Code Generator for RL78/G10 V1.05.03.02 [20 Nov 2019]
* Device(s)    : R5F10Y47
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 2020/04/03
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_adc.h"
#include "r_cg_sau.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
static uint8_t		s_txbuf[32];
static uint16_t		s_adcval[4];

//#define 	D_USE_DEMO_DISPLAY_CONSOLE

/* End user code. Do not edit comment generated here */

static void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
#ifdef	D_USE_DEMO_DISPLAY_CONSOLE
	POM0	= 0;
#endif	// D_USE_DEMO_DISPLAY_CONSOLE
	R_UART0_RX_Start();
	while(1)
	{
#ifndef	D_USE_DEMO_DISPLAY_CONSOLE
		__halt();
		if(0 == g_flg_rxfin)
		{
			ADMK		= 1U;		/* disable INTAD interrupt */
			s_adcval[0] = 16383U - g_adc_data[0];
			s_adcval[1] = 16383U - g_adc_data[1];
			s_adcval[2] = 16383U - g_adc_data[2];
			s_adcval[3] = 16383U - g_adc_data[3];
			ADMK		= 0U;		/* enable INTAD interrupt */
			continue;
		}
		g_flg_rxfin = 0;
		//
		s_txbuf[ 4]	= (s_adcval[0]     ) & 0x7F;
		s_txbuf[ 5]	= (s_adcval[0] >> 7) & 0x7F;
		s_txbuf[ 6]	= (s_adcval[1]     ) & 0x7F;
		s_txbuf[ 7]	= (s_adcval[1] >> 7) & 0x7F;
		s_txbuf[ 8]	= (s_adcval[2]     ) & 0x7F;
		s_txbuf[ 9]	= (s_adcval[2] >> 7) & 0x7F;
		s_txbuf[10]	= (s_adcval[3]     ) & 0x7F;
		s_txbuf[11]	= (s_adcval[3] >> 7) & 0x7F;
		//
		R_UART0_RX_Start();
		//
		R_UART0_Send(s_txbuf, 12);
		while(0 == g_flg_txfin);
		g_flg_txfin = 0;
#else	// D_USE_DEMO_DISPLAY_CONSOLE
		const uint8_t		s_hex2chr[] = "0123456789ABCDEF";

		ADMK		= 1U;		/* disable INTAD interrupt */
		s_txbuf[ 0]	= s_hex2chr[(g_adc_data[0] >>12) & 15];
		s_txbuf[ 1]	= s_hex2chr[(g_adc_data[0] >> 8) & 15];
		s_txbuf[ 2]	= s_hex2chr[(g_adc_data[0] >> 4) & 15];
		s_txbuf[ 3]	= s_hex2chr[(g_adc_data[0]     ) & 15];
		s_txbuf[ 4] = ',';
		s_txbuf[ 5]	= s_hex2chr[(g_adc_data[1] >>12) & 15];
		s_txbuf[ 6]	= s_hex2chr[(g_adc_data[1] >> 8) & 15];
		s_txbuf[ 7]	= s_hex2chr[(g_adc_data[1] >> 4) & 15];
		s_txbuf[ 8]	= s_hex2chr[(g_adc_data[1]     ) & 15];
		s_txbuf[ 9] = ',';
		s_txbuf[10]	= s_hex2chr[(g_adc_data[2] >>12) & 15];
		s_txbuf[11]	= s_hex2chr[(g_adc_data[2] >> 8) & 15];
		s_txbuf[12]	= s_hex2chr[(g_adc_data[2] >> 4) & 15];
		s_txbuf[13]	= s_hex2chr[(g_adc_data[2]     ) & 15];
		s_txbuf[14] = ',';
		s_txbuf[15]	= s_hex2chr[(g_adc_data[3] >>12) & 15];
		s_txbuf[16]	= s_hex2chr[(g_adc_data[3] >> 8) & 15];
		s_txbuf[17]	= s_hex2chr[(g_adc_data[3] >> 4) & 15];
		s_txbuf[18]	= s_hex2chr[(g_adc_data[3]     ) & 15];
		s_txbuf[19] = '\n';
		ADMK		= 0U;		/* enable INTAD interrupt */
		R_UART0_Send(s_txbuf, 20);
		while(0 == g_flg_txfin);
		g_flg_txfin = 0;
#endif	// D_USE_DEMO_DISPLAY_CONSOLE
	}

    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
	EI();
	//
	g_flg_rxfin	= 0;
	g_flg_txfin = 0;
	s_txbuf[0]	= D_ISC35_RCMD | D_MY_ID;
	s_txbuf[1]	= D_ISC35_SC;
	s_txbuf[2]	= 0;
	s_txbuf[3]	= 4;
	//
	R_UART0_TX_Start();
	R_ADC_Set_OperationOn();
	R_ADC_Start();

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
