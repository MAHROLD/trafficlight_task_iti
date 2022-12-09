/**************************************/
/* Description : SEV interface file   */
/* Author      : mahrold              */
/* Version     : 0.1v                 */
/* Date        : 2 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef SEV_H
#define SEV_H


tenuErrorStatus SEV_Display(uint8 u8SEVIndxCpy, uint8 u8NumCpy);
tenuErrorStatus SEV_PowerOn(uint8 u8SEVIndxCpy);
tenuErrorStatus SEV_PowerOff(uint8 u8SEVIndxCpy);


#endif
