/*
 * interface.h
 *
 *  Created on: Sep 22, 2021
 *      Author: user
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


U8 KPD_GetPressedKey(void);
void KPD_init(void);
void string_conc(U8 num);
void StringToInteger(U8 string[],U8 length);
void calc(U32 calculator);
#endif /* KPD_INTERFACE_H_ */
