/*
 * ADC_private.h
 *
 *  Created on: Oct 12, 2021
 *      Author: user
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define  ADMUX         *((volatile U8*) 0x27) //ADC multiplexer selection register

#define ADMUX_REFS1    7                      //ADC reference selection bit1
#define ADMUX_REFS0    6                      //ADC reference selection bit0
#define ADMUX_ADLAR    5

#define  ADCSRA        *((volatile U8*) 0x26)  //ADC control and status register A

#define ADCSRA_ADEN    7                       // ADC enable
#define ADCSRA_ADSC    6                       // ADC start conversion
#define ADCSRA_ADATE   5                       // Auto trigger enable
#define ADCSRA_ADIF    4                       // Interrupt flag
#define ADCSRA_ADIE    3                       // Interrupt enable
#define ADCSRA_ADPS2   2                       // prescaler bit2
#define ADCSRA_ADPS1   1                       // prescaler bit1
#define ADCSRA_ADPS0   0                       // prescaler bit0


#define  ADCH      *((volatile U8*) 0x25)    //ADC High register
#define  ADCL      *((volatile U8*) 0x24)    //ADC low register


#endif /* ADC_PRIVATE_H_ */
