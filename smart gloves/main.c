/*
 * main.c
 *
 *  Created on: Oct 12, 2021
 *      Author: user
 */

#include"avr/delay.h"
#include"std_types.h"
#include"DIO_interface.h"
#include"ADC_interface.h"
#include"LCD_interface.h"
#include"UART_interface.h"

void main(void)
{
    // TX AND RX INITIALIZE AND FUNCTION UART INIT
	DIO_set_pin_direction(Group_D,DIO_pin_D0,DIO_Input);
	DIO_set_pin_direction(Group_D,DIO_pin_D1,DIO_Output);
	//DIO_set_pin_direction(Group_D,DIO_pin_D3,DIO_Output);
	UART_Init();
	U8 arr1[4] = {'o','n','e','\0'};
	U8 arr2[4] = {'t','w','o','\0'};
	U8 arr3[7] = {'c','i','r','c','l','e','\0'};
	U8 arr4[11] = {'i','a','m',' ','h','u','n','g','r','y','\0'};
	U8 arr5[6] = {'r','a','b','i','t','\0'};

	//first and second FLEX sensor defination
	    U32 digital_1;
        U32 digital_2;

	    //for First flex pin
		DIO_set_pin_direction(Group_A,DIO_pin_A7, DIO_Input);

		//FOR second flex pin
		DIO_set_pin_direction(Group_A,DIO_pin_A6, DIO_Input);
	    ADC_init();
	    LCD_initial();

	    while(1)
	    {
	    	//for First flex DEFINATION AND SHOW ON LCD
	    	digital_1 =ADC_ChannelReading(7);
	    	//LCD_write_no(digital_1);

	    	// for second flex show in LCD
	    	 digital_2 =ADC_ChannelReading(6);

	    	 //LCD_pose_x_y(1,0);
	    	 //LCD_write_no(digital_2);

            if((digital_1>=140)  &&(digital_2<=90 ))
            {
            	UART_send_string(arr1);
            	//LCD_pose_x_y(1,10);
            	LCD_write_string(arr1);
            	_delay_ms(1000);

            }
            else if((digital_1>=140) && (digital_2>=130))
            {
            	UART_send_string(arr2);
            	//LCD_pose_x_y(1,10);
                LCD_write_string(arr2);
            	_delay_ms(1000);
            }

            else if(((digital_1>=85)&&(digital_1<=115)) && ((digital_2>=80)&&(digital_2<=100)))
                {
            	UART_send_string(arr3);
            	//LCD_pose_x_y(1,10);
                LCD_write_string(arr3);
            	_delay_ms(1000);
                }

            else if(((digital_1>=145)) &&((digital_2>=100) &&(digital_2<=125)))
                {
            	UART_send_string(arr4);
            	//LCD_pose_x_y(1,3);
                LCD_write_string(arr4);
            	_delay_ms(1000);
                }

            else if(((digital_1>=120)&&(digital_1<140)) && ((digital_2>=100)&&(digital_2<120)))
                    {
                	UART_send_string(arr5);
                	//LCD_pose_x_y(1,10);
                    LCD_write_string(arr5);
                	_delay_ms(1000);
                    }

	        _delay_ms(500);
	        LCD_clear();
	    }
	   }


