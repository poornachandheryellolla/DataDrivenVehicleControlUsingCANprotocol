#include "types.h"

#include <LPC21XX.H>

#include "adc.h"

#include "defines.h"

#include "delay.h"

void Init_ADC(void)

{

	PINSEL1|=0x15400000; //Setting up p0.27,p0.28,p0.29,p0.30 as AIN0,AIN1,AIN2,AIN3 respectively

	ADCR = (1<<PDN_BIT)|(CLKDIV<<8)|(TEN_BIT_RESOLUTION<<CLKS);

}


f32 Read_ADC(u8 chNo) {

	u32 adcVal=0;

	f32 result;

	ADCR |= (chNo<<0);   //Selecting ADC channel number (bit0 0-7 are ch0 to ch7)

						

	ADCR |= (1<<ADC_START_BIT); //start ADC conversion

	

	delay_us(3); //Wait for Conversion time (2.44us Minimun);	

			

	while(((ADCR>>DONE_BIT)&1)==1); //wait until conversion complete

	

	ADCR&=~(1<<ADC_START_BIT);  //stop ADC conversion to avoid data overrun

	

	adcVal=(ADDR>>6)&0x3FF; // 10 bit data stored in ADDR from bit 6-15

	

	result=adcVal*(3.3/1023); //step size = (2^n)-1 //n=no of bits .. 

	//result = (((adcVal*3.3)/1023)*100); //converting into actual data

	

	return result;

}

