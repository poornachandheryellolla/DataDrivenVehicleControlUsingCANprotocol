#include<LPC21XX.H>

#include "types.h"

#include "can.h"

#include "can_defines.h"

#include "defines.h"

#include "lcd.h"

#include "lcd_defines.h"

#include "ext_int.h"
#include "DS18B20_sensor.h"

#define LED 22 


volatile u32 Gear, wdCnt;

CANF txf,RcvF;

f32 dist, temp;

int main()

{
	 IODIR1 = (1<<LED);
	 IOSET1 = (1<<LED);

	InitLCD();

	Enable_Interrupts();

	Init_CAN1();

	sample();

	txf.ID = 2;

	txf.BFV.RTR = 0;

	txf.BFV.DLC = 4;

	

	while(1)

	{

	

		CmdLCD(RET_CUR_HOME);

		 

		if(Gear==0)

		{

			CmdLCD(GOTO_LINE1_POS0);

			StrLCD("Dir:FWD");
			CmdLCD(GOTO_LINE1_POS0+9);
			StrLCD("       ");

		}

		else

		{	

			CmdLCD(GOTO_LINE1_POS0);

			StrLCD("Dir:REV");

			

			

			if((READBIT(C1GSR,RBS_BIT))&&(C1RID==1))

			{

				CAN1_Rx(&RcvF);

				dist = RcvF.Data1;

				if(dist==111)

				{

					CmdLCD(GOTO_LINE1_POS0+9);

					StrLCD("D:ERROR");

				}
				  
				else

				{

					CmdLCD(GOTO_LINE1_POS0+9);

					StrLCD("D:");

					F32LCD(dist,1);

					StrLCD(" cm");

					if(dist<15)
						IOPIN1 ^= (1<<LED);	
					else
						IOSET1 = (1<<LED);
				}

			}

		}

		

		temp = data_read();

		CmdLCD(GOTO_LINE2_POS0);

		if(temp<-55)

		{

			StrLCD("Temp: ERROR");

		}

		else

		{

			StrLCD("Temp: ");

			F32LCD(temp,2);

			CharLCD(0xDF);

			StrLCD("c ");

		}		

	}

}		

