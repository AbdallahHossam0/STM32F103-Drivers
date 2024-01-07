/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <RCC.c>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <07 - 01 - 2024>
 *
 * [DESCRIPTION]: <Reset and Clock Control Source File>
 * ---------------------------------------------------------------------------------------------------
 */
#include "HAL_Drivers/RCC/RCC.h"
#include "HAL_Drivers/RCC/RCC_private.h"
#include "HAL_Drivers/RCC/RCC_config.h"

 void RCC_vSysClkInit(void){
    #if CLK_SRC == CLK_SRC_HSI
    // Clock source is HSI by default
    /* It is set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby 
       mode or in case of failure of the external 4-16 MHz oscillator used directly or indirectly as
       system clock. This bit cannot be reset if the internal 8 MHz RC is used directly or indirectly
       as system clock or is selected to become the system clock. */
	 while(BIT_IS_SET(RCC.CFGR, 2) || BIT_IS_SET(RCC.CFGR, 3));
    #elif CLK_SRC == CLK_SRC_HSE
        /* Enable the External Oscillator */
        SET_BIT(RCC.CCR, 16);
        /* Check if the External Clock has been stable or not */
        while(BIT_IS_CLEAR(RCC.CCR, 17));
        /* Convert the System clock to be based on -External Oscillator- */
        CLEAR_BIT(RCC.CFGR, 1);
        SET_BIT(RCC.CFGR, 0);
        while(BIT_IS_CLEAR(RCC.CFGR, 2) || BIT_IS_SET(RCC.CFGR, 3));
        /* stop the Internal Clock -No need for it- */
        CLEAR_BIT(RCC.CCR, 0);
    #elif CLK_SRC == CLK_SRC_PLL
        #warning "You need to configure the PLL yourself -it is not configured- Please, delete this warning line if you configure it"
        while(BIT_IS_CLEAR(RCC.CFGR, 2) || BIT_IS_CLEAR(RCC.CFGR, 3));
    #else
        #error "CLK_SRC must be either CLK_SRC_HSI, or CLK_SRC_HSE, or CLK_SRC_PLL"
    #endif

    // Set the AHB Prescaler value
    RCC.CFGR &= ~(AHB_PRESCALER_MASK);
    RCC.CFGR |= (AHB_PRESCALER << 4);

    // set the APB1 Prescaler value
    RCC.CFGR &= ~(APB1_PRESCALER_MASK);
    RCC.CFGR |= (APB1_PRESCALER << 8);

    // set the APB2 Prescaler value
    RCC.CFGR &= ~(APB2_PRESCALER);
    RCC.CFGR |= (APB2_PRESCALER << 11);

    // set the ADC Prescaler value
    RCC.CFGR &= ~(ADC_PRESCALER_MASK);
    RCC.CFGR |= (ADC_PRESCALER << 14);
 }
