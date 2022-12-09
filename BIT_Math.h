/**************************************/
/* Description : Standard Types lib   */
/* Author      : mahorld          */
/* Version     : 1.0v                 */
/* Date        : 25 Nov 2022          */
/* History     : 0.1v initial creation*/
/*               0.2v add error status*/
/*               enum                 */
/**************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Bit-Math macros*/
#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)

#endif 
