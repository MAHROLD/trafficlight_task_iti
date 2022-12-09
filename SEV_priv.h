/**************************************/
/* Description : SEV private file     */
/* Author      : mahrold           */
/* Version     : 0.1v                 */
/* Date        : 2 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef SEV_PRIV_H
#define SEV_PRIV_H
//define SEV mode anode/cathode
#define COMMON_ANODE    0
#define COMMON_CATHODE  1

/*define struct with what 7 pin names we are using
 * pin at which common anode / cathode is connected
 *  which conn commom anode/cathode
 */
typedef struct{
	uint8 au8SevCon[7];
	uint8 u8Common;
	uint8 ConMode;
}tstrconfigSet;


extern tstrconfigSet SEV_strConfigSet[SEV_MAX_NUM];
//helper fn i prefer to put it here
static void SEV_PutOnBus(uint8 u8SEVIndxCpy, uint8 u8NumCpy);

#endif
