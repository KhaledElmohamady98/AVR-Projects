/*
 * UART_interface.h
 *
 *  Created on: Oct 29, 2021
 *      Author: user
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Init(void);
void UART_send_character(U8 data);
U8 UART_receive_char(void);
void UART_send_string(U8 *str);
void UART_receive_string(U8 *str);
#endif /* UART_INTERFACE_H_ */
