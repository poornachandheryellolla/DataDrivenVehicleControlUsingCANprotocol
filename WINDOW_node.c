#include<LPC21XX.H>

#include "types.h"

#include "can.h"

#include "can_defines.h"

#include "delay.h"

#include "defines.h"


#define LEDS 0		//p0.0 AL_LEDS


int main()

{

	CANF rxf;

	int cnt=0;

	IODIR0 = (255<<LEDS);

	IOSET0 = (255<<LEDS);

	Init_CAN1();

	


	while(1)

	{
		//  i++;
		CAN1_Rx(&rxf);

		

		if(rxf.ID == 2)

		{

			cnt = rxf.Data1;
			//cnt=i;

			

			switch(cnt)

			{

				case 0: IOCLR0 = (255<<LEDS);

								IOSET0 = (0xFF<<LEDS);

								break;

				case 1: IOCLR0 = (255<<LEDS);

								IOSET0 = (0xFE<<LEDS);

								break;

				case 2: IOCLR0 = (255<<LEDS);

								IOSET0 = (0xFC<<LEDS);

								break;

				case 3: IOCLR0 = (255<<LEDS);

								IOSET0 = (0xF8<<LEDS);

								break;

				case 4: IOCLR0 = (255<<LEDS);

								IOSET0 = (0xF0<<LEDS);

								break;

				case 5: IOCLR0 = (255<<LEDS);

								IOSET0 = (0xE0<<LEDS);

								break;

				case 6: IOCLR0 = (255<<LEDS);

								IOSET0 = (0xC0<<LEDS);

								break;

				case 7: IOCLR0 = (255<<LEDS);

								IOSET0 = (0x80<<LEDS);

								break;

				case 8: IOCLR0 = (255<<LEDS);

								IOSET0 = (0x00<<LEDS);

								break;

			}

		}
	//if(i>8)
		//i=0;
		//delay_ms(500);

	}

}
