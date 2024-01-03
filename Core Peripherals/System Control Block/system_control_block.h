/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <system_control_block.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <23 - 01 - 2024>
 *
 * [DESCRIPTION]: <Header File for Cortex-M3 Core SCB peripheral>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef SYSTEM_CONTROL_BLOCK_H_
#define SYSTEM_CONTROL_BLOCK_H_

#include <stdint.h>

#define SCB_BASE_ADRESS 		UINT32_C(0xE000ED00)
#define SCB 					(*((SCB_t*)SCB_BASE_ADRESS))

#define SCB_PRIORITY_GROUP0		UINT32_C(0x00000007)	// Group priorities = 0 | Sub priorities = 16
#define SCB_PRIORITY_GROUP1		UINT32_C(0x00000006)	// Group priorities = 2 | Sub priorities = 8
#define SCB_PRIORITY_GROUP2		UINT32_C(0x00000005)	// Group priorities = 4 | Sub priorities = 4
#define SCB_PRIORITY_GROUP3		UINT32_C(0x00000004)	// Group priorities = 8 | Sub priorities = 2
#define SCB_PRIORITY_GROUP4		UINT32_C(0x00000003)	// Group priorities = 16| Sub priorities = 0

#define SCB_AIRCR_PRIORITY_GROUP_POS (8)
#define SCB_AIRCR_VECTKEYSTAT_POS	 (16)

typedef struct{
	volatile uint32_t CPUID;		/* CPUID base register -RO- */
	volatile uint32_t ICSR;			/* Interrupt control and state register -RW- */
	volatile uint32_t VTOR;			/* Vector table offset register -RW- */
	volatile uint32_t AIRCR;		/* Application interrupt and reset control register -RW- */
	volatile uint32_t SCR;			/* System control register -RW- */
	volatile uint32_t CCR;			/* Configuration and control register -RW- */
	volatile uint32_t SHPR1;		/* System handler priority register 1 -RW- */
	volatile uint32_t SHPR2;		/* System handler priority register 2 -RW- */
	volatile uint32_t SHPR3;		/* System handler priority register 3 -RW- */
	volatile uint32_t SHCRS;		/* System handler control and state register -RW- */
	volatile uint32_t CFSR;			/* Configurable fault status register -RW- */
}SCB_t;

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	SCB_setPriorityGrouping
 *
 * [DESCRIPTION]:	This function is used to set the groups and sub groups of priority
 * 					This function is usually called once on the system initialization
 * 					I have 4 bits in the priority register. we divide them into 2 groups
 * 					group1 = groups | group2 = sub groups
 *
 * [Args]:			priorityGroup(uint32_t)
 *
 * [IN]:			priorityGroup conatins the group you want to set in your project
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void SCB_setPriorityGrouping(uint32_t priorityGroup);



/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	SCB_getPriorityGrouping
 *
 * [DESCRIPTION]:	Function to get the current Priority Grouping of the systems
 *
 * [Args]:			None
 *
 * [IN]:			None
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		One of those possible directives
 * 					- SCB_PRIORITY_GROUP0: Group priorities = 0 | Sub priorities = 16
 * 					- SCB_PRIORITY_GROUP1: Group priorities = 2 | Sub priorities = 8
 * 					- SCB_PRIORITY_GROUP2: Group priorities = 4 | Sub priorities = 4
 * 					- SCB_PRIORITY_GROUP3: Group priorities = 8 | Sub priorities = 2
 * 					- SCB_PRIORITY_GROUP4: Group priorities = 16| Sub priorities = 0
 * ---------------------------------------------------------------------------------------------------
 */
uint32_t SCB_getPriorityGrouping(void);

#endif /* SYSTEM_CONTROL_BLOCK_H_ */
