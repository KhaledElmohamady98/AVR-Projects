/*
 * ADC_program.c
 *
 *  Created on: Oct 12, 2021
 *      Author: user
 */

#include"std_types.h"
#include"BIT_CALC.h"

#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_config.h"


void ADC_init(void)
{
	//Set prescaler to divide 128

	//ADCSRA &=init_pc;
	set_bit(ADCSRA,ADCSRA_ADPS2);
	set_bit(ADCSRA,ADCSRA_ADPS1);
	set_bit(ADCSRA,ADCSRA_ADPS0);
	//ADCSRA |=ADC_PREC

	//AVCC as reference voltage
	set_bit(ADMUX,ADMUX_REFS0);
	clear_bit(ADMUX,ADMUX_REFS1);


	//activate left adjust result
	set_bit(ADMUX,ADMUX_ADLAR);

	//Enable peripheral
	set_bit(ADCSRA,ADCSRA_ADEN);
}
U8 ADC_ChannelReading(U8 channel)
{
     //clear the mux bit in ADMUX register
	ADMUX &= 0b11100000;
	ADMUX |= channel;

	//start conversion
	set_bit(ADCSRA,ADCSRA_ADSC);

	//polling (busy waiting) until the conversion complete the flag
    while(get_bit(ADCSRA,ADCSRA_ADIF)==0);

    //clear the conversion complete flag
    set_bit(ADCSRA,ADCSRA_ADIF);

    return ADCH;
}


U16 ADC_Read_10(U8 channel){
	ADMUX &= 0b11100000; // channel selection
	ADMUX |= channel;

	set_bit(ADCSRA,6); // start conversion(default single conversion)

	while(get_bit(ADCSRA,4)==0);
	set_bit(ADCSRA,4);  //clear flag
	U16 res = (ADCL>>6);
	res |= (((U16)ADCH)<<2) ;
	return res;
}

