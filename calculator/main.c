/*
 * main.c
 *
 *  Created on: Sep 23, 2021
 *      Author: user
 */


#include"std_types.h"
#include"BIT_CALC.h"
#define F_CPU 8000000
#include "avr/delay.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"

void main(void)
{


	U32 local_key;
    KPD_init();
    LCD_initial();
while(1)
{
  do
  {
   local_key = KPD_GetPressedKey();
  }while(local_key == 0);

  NumberOrSymbol(local_key);
  string_conc(local_key);

   }
}





