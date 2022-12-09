/**************************************/
/* Description : SEV program file file   */
/* Author      : mahrold              */
/* Version     : 0.1v                 */
/* Date        : 2 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "SEV.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"


tenuErrorStatus SEV_Display(uint8 u8SEVIndxCpy, uint8 u8NumCpy)
{
	tenuErrorStatus enuReturnLoc = EOK;
	uint8 au8AnaodeLoc[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F} ;
	if(u8SEVIndxCpy < SEV_MAX_NUM)
	{
		if (u8NumCpy < 10)
		{
			//check which mode it is
			if(SEV_strConfigSet[u8SEVIndxCpy].ConMode == COMMON_CATHODE )
			{
				//write the num using the helper fun
				SEV_PutOnBus( u8SEVIndxCpy, au8AnaodeLoc[u8NumCpy]);
			}else
			{
				//cathode mode
				SEV_PutOnBus( u8SEVIndxCpy, ~au8AnaodeLoc[u8NumCpy]);
			}

		}else
		{
			enuReturnLoc = PARAM_OUT_RANGE;
		}

	}else
	{
		enuReturnLoc = PARAM_OUT_RANGE;
	}

	return enuReturnLoc;

}
tenuErrorStatus SEV_PowerOn(uint8 u8SEVIndxCpy)
{	//WRITING HIGH OR LOW on the common anode or cathode pin
	tenuErrorStatus enuReturnLoc = EOK ;
	if(u8SEVIndxCpy < SEV_MAX_NUM)
	{
		if(SEV_strConfigSet[u8SEVIndxCpy].ConMode == COMMON_CATHODE)
		{
			//the aray is configered in anode we put low here
			enuReturnLoc = DIO_enuWritePin(SEV_strConfigSet[u8SEVIndxCpy].u8Common,DIO_LOW);
		}else
		{
			enuReturnLoc = DIO_enuWritePin(SEV_strConfigSet[u8SEVIndxCpy].u8Common,DIO_HIGH);
		}
	}else
	{
	enuReturnLoc = PARAM_OUT_RANGE;
	}
	return enuReturnLoc;
}
tenuErrorStatus SEV_PowerOff(uint8 u8SEVIndxCpy)


{
	//we do the same as above but change the value to the reverse of reverse the cathode and make it anode
	tenuErrorStatus enuReturnLoc = EOK ;
	if(u8SEVIndxCpy < SEV_MAX_NUM)
	{
		if(SEV_strConfigSet[u8SEVIndxCpy].ConMode == COMMON_ANODE)
		{
			//the aray is configered in anode we put low here
			enuReturnLoc = DIO_enuWritePin(SEV_strConfigSet[u8SEVIndxCpy].u8Common,DIO_LOW);
		}else
		{
			enuReturnLoc = DIO_enuWritePin(SEV_strConfigSet[u8SEVIndxCpy].u8Common,DIO_HIGH);
		}
	}else
	{
	enuReturnLoc = PARAM_OUT_RANGE;
	}
	return enuReturnLoc;
}
//helper fn static we use it to write the 7 pins to draw num using write group fn from dio
static void SEV_PutOnBus(uint8 u8SEVIndxCpy, uint8 u8NumCpy)
{
	uint8 u8CntLoc;
	uint8 au8PinValuesLoc[7];
	for(u8CntLoc=0;u8CntLoc < 7;u8CntLoc++)
	{
		au8PinValuesLoc[u8CntLoc] = GET_BIT(u8NumCpy,u8CntLoc);

	}
	//after getting all bits in array we write group it
	DIO_enuWriteGroup(SEV_strConfigSet[u8SEVIndxCpy].au8SevCon,au8PinValuesLoc,7);

}
