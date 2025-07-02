//CAN.H

#ifndef _CAN_H

#define _CAN_H


#include "types.h"


typedef struct CAN_Frame

{

	u32 ID;

	

	struct BitField

	{

		u8 RTR: 1;

		u8 DLC: 4;

	}BFV;

	

	u32 Data1, Data2;

	

}CANF;

void Init_CAN1(void);

void CAN1_Tx(CANF txF);

void CAN1_Rx(CANF *rxF);

#endif
