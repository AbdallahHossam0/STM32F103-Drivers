/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <systick.c>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <08 - 01 - 2024>
 *
 * [DESCRIPTION]: <Source File for the system timer in STM32F103>
 * ---------------------------------------------------------------------------------------------------
 */


#include "Cortex-M3 Core/systick.h"


// <Tested>
void systick_counterEnable(void){
	SET_BIT(SYSTICK.STK_CTRL, ENABLE);
}
// <Tested>
void systick_counterDisable(void){
	CLEAR_BIT(SYSTICK.STK_CTRL, ENABLE);
}
// <Tested>
void systick_setReload(uint32_t value){
	SYSTICK.STK_LOAD = value & 0x00FFFFFF;
}
// <Tested>
void systick_setClockSource(ClkSrc_t clkSource){
	if(clkSource){
		SET_BIT(SYSTICK.STK_CTRL, CLKSOURCE);
	}
	else{
		CLEAR_BIT(SYSTICK.STK_CTRL, CLKSOURCE);
	}
}
// <Tested>
void systick_interruptEnable(void){
	SET_BIT(SYSTICK.STK_CTRL, TICKINT);
}
// <Tested>
void systick_interruptDisable(void){
	CLEAR_BIT(SYSTICK.STK_CTRL, TICKINT);
}
// <Tested>
void systick_reset(void){
	SYSTICK.STK_VAL = 0;
}
// <Tested>
void systick_waitBlocking(uint32_t value, ClkSrc_t clkSource){
	systick_reset();
	systick_setClockSource(clkSource);
	systick_setReload(value);
	systick_interruptDisable();
	systick_counterEnable();
	while(!systick_getCountFlag());
	systick_counterDisable();
	systick_setReload(0);
	systick_reset();
}
// <Tested>
void systick_singleInterval(uint32_t value, ClkSrc_t clkSource){
	systick_reset();
	systick_setClockSource(clkSource);
	systick_setReload(value);
	systick_counterEnable();
}
// <Tested>
uint32_t systick_getReload(void){
	return SYSTICK.STK_LOAD & 0x00FFFFFF;
}
// <Tested>
uint32_t systick_getValue(void){
	return SYSTICK.STK_VAL & 0x00FFFFFF;
}
// <Tested>
uint8_t systick_getCountFlag(void){
	return (BIT_IS_SET(SYSTICK.STK_CTRL, 16)) ? 1 : 0;
}
