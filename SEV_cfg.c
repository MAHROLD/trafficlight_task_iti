/**************************************/
/* Description : SEV config file .c   */
/* Author      : mahrold          */
/* Version     : 0.1v                 */
/* Date        : 2 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "DIO.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"

//take var of configset struct and configset
tstrconfigSet SEV_strConfigSet[SEV_MAX_NUM]=
{
		{
				{
							/* A                B               C           */
							DIO_PIN_NUM_0 , DIO_PIN_NUM_1 , DIO_PIN_NUM_8  ,
							/* D                E               F           */
							DIO_PIN_NUM_9  , DIO_PIN_NUM_16 , DIO_PIN_NUM_17  ,
							/* G                                           */
							DIO_PIN_NUM_24
				},
				DIO_PIN_NUM_31 ,
				COMMON_CATHODE


		},

		{

				{
							/* A                B               C           */
							DIO_PIN_NUM_0 , DIO_PIN_NUM_1 , DIO_PIN_NUM_8  ,
							/* D                E               F           */
							DIO_PIN_NUM_9  , DIO_PIN_NUM_16 , DIO_PIN_NUM_17  ,
							/* G                                           */
							DIO_PIN_NUM_24
				},
				DIO_PIN_NUM_30 ,
				COMMON_CATHODE





		}
};
