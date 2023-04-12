/*
 * UART_program.c
 *
 *  Created on: Oct 29, 2021
 *      Author: user
 */

#include"BIT_CALC.h"
#include"std_types.h"
#include"UART_interface.h"
#include"UART_private.h"



void UART_Init(void)
{
    UBRRH = 0b00000000;
	UBRRL = 51;
	UCSRC = 0b10000110;
	UCSRB = 0b00011000;

}


void UART_send_character(U8 data)
{

	while(get_bit(UCSRA,5)==0);
	UDR = data;
}
U8 UART_receive_char(void)
{
 while(get_bit(UCSRA,7)==0);
 return UDR ;
}

void UART_send_string(U8 *str)
{
	while(*str !='\0')
	{
		UART_send_character(*str);
		str++;
	}
}


void UART_receive_string(U8 *str)
{
	U8 i=0;
	while(i<8)
	{
	    str[i]=UART_receive_char();
		i++;
	}
    str[i]='\0';
}
