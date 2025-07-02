//ext_int.c


#include<LPC21XX.H>

#include "ext_int.h"

#include "can.h"

#include "can_defines.h"




extern volatile int Gear, wdCnt;

extern CANF txf;


void Enable_Interrupts(void)

{

	//p0.1, p0.3, p0.7, p0.9 pins functions are selected as external interrupts

	PINSEL0 |= (3<<2)|(3<<6)|(3<<14); //0x000CC0CC

	

	//Select all interrupts as IRQ 

	VICIntSelect = 0x0;

	

	//Toggle_Gear is 1st priority and enable it.

	VICVectCntl0 = EI0_CH | (1<<5);

	VICVectAddr0 = (unsigned long int)Toggle_Gear;

	

	//Window_Close 2nd priority and enable it

	VICVectCntl1 = EI1_CH | (1<<5);

	VICVectAddr1 = (unsigned long int)Window_Close;

	

	//Window_Open is 3rd priority and enable it

	VICVectCntl2 = EI2_CH | (1<<5);

	VICVectAddr2 = (unsigned long int)Window_Open;

	

	//Enable all 3 interrupts

	VICIntEnable = (1<<EI0_CH) | (1<<EI1_CH) | (1<<EI2_CH);

	

	//set as Edge trigger

	EXTMODE = (1<<0)|(1<<1)|(1<<2);

	//set Active low Edge 

	//EXTPOLAR = (0<<0)|(0<<1)|(0<<2);


}


void Toggle_Gear(void)__irq

{

	//Toggle_Gear

	Gear ^= 1;

	//clear EI0 flag

	EXTINT = (1<<0);

	//To finish isr

	VICVectAddr = 0x0;

}


void Window_Close(void)__irq

{

	if(wdCnt<8)

	{

		wdCnt++;

		txf.Data1 = wdCnt;

		CAN1_Tx(txf);

	}

	

	EXTINT = (1<<1);

	VICVectAddr = 0x0;


}


void Window_Open(void)__irq

{

	if(wdCnt>0)

	{

		wdCnt--;

		txf.Data1 = wdCnt;

		CAN1_Tx(txf);

	}

	

	EXTINT = (1<<2);

	VICVectAddr = 0x0;

	

}
