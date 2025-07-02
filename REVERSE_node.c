#include<LPC21XX.H>

#include "can.h"

#include "can_defines.h"

#include "types.h"

#include "defines.h"

#include "delay.h"

#include "adc.h"

#define LED 8

  	f32 AnalogRead=0,DigitalVal=0,distance=0;
int main()

{
	CANF txf;
	

	Init_CAN1();

	Init_ADC();

	txf.ID=1;

	txf.BFV.RTR=0;

	txf.BFV.DLC=4;

	

	while(1)

	{

		AnalogRead = Read_ADC(CH0);

		DigitalVal = AnalogRead*(1024/5);


		distance = (6787/(DigitalVal-3))-4;

		

		if(distance>=6 && distance<81)

		{

			txf.Data1 = distance;

			CAN1_Tx(txf);

			
		}
		delay_ms(100);
	 }
		













		/*if(DV==3) {

			txF.BFV.DLC=1;

			txF.Data[0]='E'; //Error Calculatiions sends frame

			CAN1_Tx(txF);

			txF.BFV.DLC=4;

		}

		else {

			dist=(6787/(DV-3))-4;

			if((dist<81)&&(dist>5)) {

				for(i=0;i<4;i++) 

					txF.Data[i]=((u8 *)&dist)[i];

				CAN1_Tx(txF);

			}

		}

		delay_ms(100);*/

}	

