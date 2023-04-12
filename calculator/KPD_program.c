/*
 * program.c
 *
 *  Created on: Sep 22, 2021
 *      Author: user
 */
#include"string.h"
#include "std_types.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"





//main finction of KBD
U8 KPD_GetPressedKey(void)
{

	U8 Press_key = KPD_no_pressed_key ;
	U8 column;
	U8 row;
	U8 pin_state;
    static U8 KBD_Arr[Row_NB][Column_NB] = KBD_Arr_Value;
    static U8 Arr_Column[Column_NB] = {KBD_column_pin0 ,KBD_column_pin1 ,KBD_column_pin2 ,KBD_column_pin3 };
    static U8 Arr_Row[Row_NB] = {KBD_row_pin0 ,KBD_row_pin1 ,KBD_row_pin2 ,KBD_row_pin3};

    for(column=0;column<Column_NB;column++)
    {
    	// make the column index pin = 0
       DIO_set_pin_value(KPD_port,Arr_Column[column],DIO_Low);


       // read the value of each row pin in one of column index
       for(row=0;row<Row_NB;row++)
       {
    	  DIO_get_pin_value(KPD_port,Arr_Row[row],&pin_state);

    	  // output the value and the number of switch which the user pressed
       if(DIO_Low == pin_state)
       {
    	   Press_key =  KBD_Arr[row][column];

    	   while( DIO_Low == pin_state)
    	   {

    		   DIO_get_pin_value(KPD_port,Arr_Row[row],&pin_state);
    	   }
    	   return Press_key;
       }

       }
       //after check column index return the value of column index = 1

       DIO_set_pin_value(KPD_port,Arr_Column[column],DIO_High);
    }


	return Press_key;
}


//KPD intialization pins of KPD port
void KPD_init(void)
{
	  for(int pin_num=0;pin_num<4;pin_num++)
	        {
	    	DIO_set_pin_direction(KPD_port,pin_num,DIO_Output);
	    	DIO_set_pin_value(KPD_port,pin_num,DIO_High);
	        }

	        for(int pin_num=7;pin_num>3;pin_num--)
	        {
	        	DIO_set_pin_direction(KPD_port,pin_num,DIO_Input);
	            DIO_set_pin_value(KPD_port,pin_num,DIO_High);
	        }


}

//collect the number in one string
void string_conc(U8 num5)
{
	static U8 str1[20];
	static U8 index = 0;
	if((num5 != '+') &&(num5!='c') && (num5!='=') && (num5!='-') && (num5!='*') && (num5!='/') )
	{
		str1[index] = num5;
		index++;
	}
	else if((num5=='+') || (num5=='=') || (num5=='-') || (num5=='*') || (num5=='/'))
	{
		str1[index] = '\0';
		StringToInteger(str1,index);
		for(int i=index;i>=0;i--)
		{
			str1[i]=0;
		}
		calc(num5);
	}
}

//convert string to digit
void StringToInteger(U8 string[],U8 length)
{
	U32 digit_o;;
	U32 j=1;
	U32 IntValue=0;
	for(int i =(length-1);i>=0;i--)
	{
	digit_o = string[i];
	IntValue = IntValue +(digit_o * j);
	j= j*10;
	}
	calc(IntValue);
}

//calculation function
void calc(U32 calculator)
{
	static U32 num3 =0;
	static U32 num2 =0;
	static U8 op_o =0;
	if((num3==0) && (calculator!='+') && (calculator!='c'))
	{
		num3 = calculator;
	}
	else if( (calculator=='+') || (calculator=='-') || (calculator =='*') || (calculator =='/') )
		{

		switch(calculator){

		case '+':
		op_o=1;
		break;

		case '-':
		op_o=2;
		break;

		case '*':
		op_o=3;
		break;

		case '/':
		op_o=4;
		break;
		}
		}

	else if((num2 == 0) &&(calculator !='+') && (calculator!='c') )
	{
		num2 = calculator;
	}

	else if(calculator==('='))
	{
        switch(op_o){
        case 1:
  		  LCD_write_no(num3 + num2);
  		  num3 = 0;
  		  num2 = 0;
  		  break;

		case 2:
		  LCD_write_no(num3 - num2);
		  num3 = 0;
		  num2 = 0;
		  break;


        case 3:
         LCD_write_no(num3 * num2);
         num3 = 0;
         num2 = 0;
         break;

        case 4:
          LCD_write_no(num3 / num2);
          num3 = 0;
          num2 = 0;
          break;
         }
	}

	else if(calculator == 'c')
	{
		num3 = 0;
		num2 = 0;
	}
	}


