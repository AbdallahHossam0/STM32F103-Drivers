/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <system_control_block.c>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <23 - 01 - 2024>
 *
 * [DESCRIPTION]: <Source File for Cortex-M3 Core SCB peripheral>
 * ---------------------------------------------------------------------------------------------------
 */

#include "Cortex-M3 Core/system_control_block.h"

void SCB_setPriorityGrouping(uint32_t priorityGroup){
	priorityGroup &= UINT32_C(0x07);
	uint32_t regValue = SCB.AIRCR;
	regValue &= ~(UINT32_C(0xFFFF0000) | UINT32_C(0x00000700));
	regValue |= ((0x000005FA << SCB_AIRCR_VECTKEYSTAT_POS)  & UINT32_C(0xFFFF0000)) |
			((priorityGroup << SCB_AIRCR_PRIORITY_GROUP_POS) & UINT32_C(0x00000700));
	SCB.AIRCR = regValue;
}

uint32_t SCB_getPriorityGrouping(void){
	return (SCB.AIRCR & (0x07) << 8) >> 8;
}
