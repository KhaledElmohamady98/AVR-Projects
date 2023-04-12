/*
 * ADC_interface.h
 *
 *  Created on: Oct 12, 2021
 *      Author: user
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_init(void);
U8 ADC_ChannelReading(U8 channel);
U16 ADC_Read_10(U8 channel);

#endif /* ADC_INTERFACE_H_ */
