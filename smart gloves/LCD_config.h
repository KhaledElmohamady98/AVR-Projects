/*
 * LCD_config.h
 *
 *  Created on: Sep 11, 2021
 *      Author: user
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

//define control pin
#define LCD_control_port   Group_A
#define LCD_rs_pin         DIO_pin_A2
#define LCD_rw_pin         DIO_pin_A1
#define LCD_E_pin          DIO_pin_A0

//define data pin

#define LCD_data_port  Group_C
#define LCD_data_pin0  DIO_pin_C0
#define LCD_data_pin1  DIO_pin_C1
#define LCD_data_pin2  DIO_pin_C2
#define LCD_data_pin3  DIO_pin_C3
#define LCD_data_pin4  DIO_pin_C4
#define LCD_data_pin5  DIO_pin_C5
#define LCD_data_pin6  DIO_pin_C6
#define LCD_data_pin7  DIO_pin_C7

#endif /* LCD_CONFIG_H_ */
