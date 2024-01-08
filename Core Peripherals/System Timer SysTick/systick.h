/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <systick.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <08 - 01 - 2024>
 *
 * [DESCRIPTION]: <Header File for the system timer in STM32F103>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef CORTEX_M3_CORE_SYSTICK_H_
#define CORTEX_M3_CORE_SYSTICK_H_

#include <stdint.h>
#include "Common/common_macros.h"

// this struct contains the regestes of the system timer
typedef struct{
	volatile uint32_t STK_CTRL; 	// SysTick Control and Status Register	<R|W>
	volatile uint32_t STK_LOAD;		// SysTick Reload Value Register		<R|W>
	volatile uint32_t STK_VAL;		// SysTick Current Value Register		<R|W>
	volatile uint32_t STK_CALIB;	// SysTick Calibration Value Register	<RO> "Not needed"
}SysTick_t;

// enum to choose the clock source for the system timer
typedef enum{
	PROCESSOR_CLK_DIVIDED_BY_8 = 0,
	PROCESSOR_CLK = 1
}ClkSrc_t;

#define SYSTICK_BASE_ADDR	UINT32_C(0xE000E010)
#define SYSTICK 			(*(SysTick_t*)SYSTICK_BASE_ADDR)

/* ========== BITS Positions ========== */
#define ENABLE				UINT8_C(0)	// Enables the counter -SysTick timer-
#define TICKINT				UINT8_C(1)	// Enables SysTick exception request
#define CLKSOURCE			UINT8_C(2)	// Indicates the clock source (0: processor clock / 8, 1: processor clock)
#define COUNTFLAG			UINT8_C(16)	// Returns 1 if timer counted to 0 since last time this was read


/* ======================= Function Interfaces  ======================= */

/* ======================= SysTick Configurations  ======================= */
void systick_counterEnable(void);
void systick_counterDisable(void);
void systick_setReload(uint32_t value);
void systick_setClockSource(ClkSrc_t clkSource);
void systick_interruptEnable(void);
void systick_interruptDisable(void);
void systick_reset(void);

/* ======================= SysTick Helper Function  ======================= */
void systick_waitBlocking(uint32_t value, ClkSrc_t clkSource);
void systick_singleInterval(uint32_t value, ClkSrc_t clkSource);

/* ======================= SysTick getters  ======================= */
uint32_t systick_getReload(void);
uint32_t systick_getValue(void);
uint8_t systick_getCountFlag(void);

#endif /* CORTEX_M3_CORE_SYSTICK_H_ */
