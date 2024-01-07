/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <RCC.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <07 - 01 - 2024>
 *
 * [DESCRIPTION]: <Reset and Clock Control Header File>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef _RCC_H_
#define _RCC_H_

#include "RCC_private.h"
#include "Common/common_macros.h"

// ! You must call the define for the peripheral before you initialize it
// ! in the main program and after the RCC_vSysClkInit function is called

/* =================== AHB peripheral clock Enable  =================== */
#define RCC_DMA1_CLK_ENABLE (SET_BIT(RCC.AHBENR, 0))
#define RCC_SRAM_CLK_ENABLE (SET_BIT(RCC.AHBENR, 2))
#define RCC_CRC_CLK_ENABLE (SET_BIT(RCC.AHBENR, 6))

/* =================== AHB peripheral clock Disable =================== */
#define RCC_DMA1_CLK_DISABLE (CLEAR_BIT(RCC.AHBENR, 0))
#define RCC_SRAM_CLK_DISABLE (CLEAR_BIT(RCC.AHBENR, 2))
#define RCC_CRC_CLK_DISABLE (CLEAR_BIT(RCC.AHBENR, 6))

/* =================== APB1 peripheral clock Enable =================== */

// Macros to Enable the clock for the GPIO Ports
#define RCC_TIM2_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 0))
#define RCC_TIM3_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 1))
#define RCC_TIM4_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 2))
#define RCC_TIM5_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 3))
#define RCC_TIM6_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 4))
#define RCC_TIM7_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 5))
#define RCC_WWDG_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 11))
#define RCC_SPI2_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 14))
#define RCC_USART2_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 17))
#define RCC_USART3_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 18))
#define RCC_I2C1_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 21))
#define RCC_I2C2_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 22))
#define RCC_USB_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 23))
#define RCC_CAN_CLK_ENABLE (SET_BIT(RCC.APB1ENR, 25))

/* =================== APB1 peripheral clock Disable =================== */

// Macros to Disable the clock for the GPIO Ports
#define RCC_TIM2_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 0))
#define RCC_TIM3_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 1))
#define RCC_TIM4_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 2))
#define RCC_TIM5_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 3))
#define RCC_TIM6_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 4))
#define RCC_TIM7_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 5))
#define RCC_WWDG_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 11))
#define RCC_SPI2_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 14))
#define RCC_USART2_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 17))
#define RCC_USART3_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 18))
#define RCC_I2C1_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 21))
#define RCC_I2C2_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 22))
#define RCC_USB_CLK_DISABLE (CLEAR_BIT(RCC.APB1ENR, 23))
#define RCC_CAN_CLK_DISABLE() (CLEAR_BIT(RCC.APB1ENR, 25))

/* =================== APB2 peripheral clock Enable =================== */

// Macros to Enable the clock for the GPIO Ports
#define RCC_AFIO_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 0))
#define RCC_GPIOA_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 2))
#define RCC_GPIOB_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 3))
#define RCC_GPIOC_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 4))
#define RCC_ADC1_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 9))
#define RCC_ADC2_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 10))
#define RCC_TIM1_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 11))
#define RCC_SPI1_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 12))
#define RCC_USART1_CLK_ENABLE() (SET_BIT(RCC.APB2ENR, 14))

/* =================== APB2 peripheral clock Disable =================== */

// Macros to Disable the clock for the GPIO Ports
#define RCC_AFIO_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 0))
#define RCC_GPIOA_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 2))
#define RCC_GPIOB_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 3))
#define RCC_GPIOC_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 4))
#define RCC_ADC1_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 9))
#define RCC_ADC2_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 10))
#define RCC_TIM1_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 11))
#define RCC_SPI1_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 12))
#define RCC_USART1_CLK_DISABLE() (CLEAR_BIT(RCC.APB2ENR, 14))

/* ======================= Function Interfaces  ======================= */
/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: RCC_vSysClkInit
 *
 * [DESCRIPTION]:   Function to initialize the system clock depending on the pre-linked configuration
 *                  in the RCC_config.h file. It is also adjust the AHB, APB1, APB2 Prescaler depending
 *                  on the pre-linked configuration in the RCC_config.h file.
 *
 * [Args]:          None
 * 
 * [IN]:            None
 * 
 * [OUT]:           None
 * 
 * [IN / OUT]:      None
 *
 * [RETURNS]:       void
 * ---------------------------------------------------------------------------------------------------
 */
void RCC_vSysClkInit(void);

#endif /* _RCC_H_ */
