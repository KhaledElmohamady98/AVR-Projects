/*
 * UART_private.h
 *
 *  Created on: Oct 29, 2021
 *      Author: user
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR    *((volatile U8 *)0X2C)
#define UCSRC  *((volatile U8 *)0X40)
#define UBRRH  *((volatile U8 *)0X40)
#define UCSRB  *((volatile U8 *)0X2A)
#define UBRRL  *((volatile U8 *)0X29)
#define UCSRA  *((volatile U8 *)0X2B)

#endif /* UART_PRIVATE_H_ */
