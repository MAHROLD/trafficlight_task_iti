/*
 * main.c
 *
 *  Created on: Dec 2, 2022
 *      Author: nadin
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>

#include "DIO.h"
#include "SEV.h"

void main(void)
{
	uint8 Local_u8Counter = 0;
	uint8 Local_u8Counter2 =9;
	uint8 SegCntLoc;
	uint8 CntLoc=0;
		DIO_voidInit();
		while(1)
		{
			DIO_enuWritePin(DIO_PIN_NUM_5, DIO_HIGH); //5 is red
			for(SegCntLoc=30;SegCntLoc>0;SegCntLoc--)
			{
				for(CntLoc=0;CntLoc < 25 ; CntLoc++){
							SEV_PowerOff(1);
							 SEV_PowerOn(0);
							SEV_Display(0,SegCntLoc%10);
							_delay_ms(20);
							SEV_PowerOff(0);
							SEV_PowerOn(1);
							SEV_Display(1,SegCntLoc/10);
							_delay_ms(20);
							}

			}
			DIO_enuWritePin(DIO_PIN_NUM_5, DIO_LOW); //5 is red



			DIO_enuWritePin(DIO_PIN_NUM_6, DIO_HIGH); //6 is green
			for(SegCntLoc=40;SegCntLoc>0;SegCntLoc--)
			{
				for(CntLoc=0;CntLoc < 25 ; CntLoc++)
				{
					SEV_PowerOff(1);
					SEV_PowerOn(0);
					SEV_Display(0,SegCntLoc%10);
					_delay_ms(20);
					SEV_PowerOff(0);
					SEV_PowerOn(1);
					SEV_Display(1,SegCntLoc/10);
					_delay_ms(20);
				}

			}
			DIO_enuWritePin(DIO_PIN_NUM_6, DIO_LOW); //6 is green


			DIO_enuWritePin(DIO_PIN_NUM_7, DIO_HIGH); //7 is yellow
			for(SegCntLoc=20;SegCntLoc>0;SegCntLoc--)
			{
				for(CntLoc=0;CntLoc < 25 ; CntLoc++)
				{
					SEV_PowerOff(1);
					SEV_PowerOn(0);
					SEV_Display(0,SegCntLoc%10);
					_delay_ms(20);
					SEV_PowerOff(0);
					SEV_PowerOn(1);
					SEV_Display(1,SegCntLoc/10);
					_delay_ms(20);
				}

			}
			DIO_enuWritePin(DIO_PIN_NUM_7, DIO_LOW); //7 is yellow


		}
}
