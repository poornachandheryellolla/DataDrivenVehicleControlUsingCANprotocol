//can.c


#include<LPC21XX.H>

#include "types.h"

#include "defines.h"

#include "delay.h"

#include "can.h"

#include "can_defines.h"


void Init_CAN1(void)

{

	//cfg p0.25 pin as RD1 (Receive Data 1)

	PINSEL1 |=0x15440000;
//					  000000000000000000000000000000000
	//make CAN1 into Reset mode

	C1MOD = 1;

	//accept all received messages

	AFMR = (0<<AccOFF_BIT) | (1<<AccBP_BIT);

	//set baud rate

	C1BTR = BTR_LVAL;

	//make CAN1 controller to Normal Mode

	C1MOD = 0;

}


void CAN1_Tx(CANF txF)

{

	//check whether Transmit Buffer is empty or not

	while(((C1GSR>>TBS1_BIT)&1)==0);

	

	//copy 11-bit Tx ID into C1TID1

	C1TID1 = txF.ID;

	//cfg RTR and DLC of C1TFI1

	C1TFI1 = (txF.BFV.RTR<<RTR_BIT) | (txF.BFV.DLC<<DLC_BITS);

	

	//if data frame to transmit, copy data values into Transmit data registers

	if(txF.BFV.RTR==0)

	{

		//copy first 4 bytes into C1TDA1

		C1TDA1 = (txF.Data1);

		//copy next 4 bytes into C1TDB1

		C1TDB1 = (txF.Data2);

	}

		//Select Tx Buffer 1 (STB1) and Start transmission

		C1CMR = (1<<STB1_BIT) | (1<<TR_BIT);

		//wait until Tx complete

		while(((C1GSR>>TCS1_BIT)&1)==0);


}


void CAN1_Rx(CANF *rxF)

{

	//wait until CANF is received

	while(((C1GSR>>RBS_BIT)&1)==0);

	

	//copy 11-bit CANid of received frame

	rxF->ID = C1RID;

	

	//read and extract data/remote frame 

	rxF->BFV.RTR = (C1RFS>>RTR_BIT)&1;

	

	//read and extract data length

	rxF->BFV.DLC = (C1RFS>>DLC_BITS)&0x0F;

	

	//check if received frame is data frame, then extract data bytes

	if(rxF->BFV.RTR==0)

	{

		//read first 4 bytes data

		rxF->Data1 = C1RDA;

		//read next 4 bytes dtata

		rxF->Data2 = C1RDB;

		

	}

	

	//Release Receive Buffers

	C1CMR = (1<<RRB_BIT);

	

}

