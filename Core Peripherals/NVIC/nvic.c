/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <nvic.c>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <23 - 01 - 2024>
 *
 * [DESCRIPTION]: <Source File for Cortex-M3 Core NVIC peripheral>
 * ---------------------------------------------------------------------------------------------------
 */

#include "Cortex-M3 Core/nvic.h"


void NVIC_EnableIRQ(IRQ_t IRQn){
	if(IRQn < 0 || IRQn > 42){
		return;
	}
	NVIC.ISER[IRQn >> 5] = (1 << (IRQn & 0x1F));
}


void NVIC_DisableIRQ(IRQ_t IRQn){
	if(IRQn < 0 || IRQn > 42){
		return;
	}
	NVIC.ICER[IRQn >> 5] = (1 << (IRQn & 0x1F));
}


void NVIC_SetPendingIRQ(IRQ_t IRQn){
	if(IRQn < 0 || IRQn > 42){
		return;
	}
	NVIC.ISPR[IRQn >> 5] = (1 << (IRQn & 0x1F));
}


void NVIC_ClearPendingIRQ(IRQ_t IRQn){
	if(IRQn < 0 || IRQn > 42){
		return;
	}
	NVIC.ICPR[IRQn >> 5] = (1 << (IRQn & 0x1F));
}


uint8_t NVIC_GetActive(IRQ_t IRQn){
	if(IRQn < 0 || IRQn > 42){
		return 0;
	}
	return NVIC.IABR[IRQn >> 5] & (1 << (IRQn & 0x1F)) ? UINT8_C(1): UINT8_C(0);
}

void NVIC_setPriority(IRQ_t IRQn, uint8_t priority){
	if(IRQn < 0 || IRQn > 42){
		return 0;
	}
	NVIC.IPR[IRQn] = (priority & 0x0F)<< 0x04;
}

uint8_t NVIC_getPriority(IRQ_t IRQn){
	if(IRQn < 0 || IRQn > 42){
		return 0;
	}
	return (NVIC.IPR[IRQn] >> 0x04) & 0x0F;
}



