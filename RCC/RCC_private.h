/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <RCC_private.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <07 - 01 - 2024>
 *
 * [DESCRIPTION]: <Reset and Clock Control Private Header File>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_

#include <stdint.h>

typedef struct {
    volatile uint32_t CCR;      /* Clock control register 					<0x00> */
    volatile uint32_t CFGR;     /* Clock configuration register 			<0x04> */
    volatile uint32_t CIR;      /* Clock interrupt register 				<0x08> */
    volatile uint32_t APB2RSTR; /* APB2 peripheral reset register 			<0x0C> */
    volatile uint32_t APB1RSTR; /* APB1 peripheral reset register 			<0x10> */
    volatile uint32_t AHBENR;   /* AHB peripheral clock enable register 	<0x14> */
    volatile uint32_t APB2ENR;  /* APB2 peripheral clock enable register 	<0x18> */
    volatile uint32_t APB1ENR;  /* APB1 peripheral clock enable register 	<0x1C> */
    volatile uint32_t BDCR;     /* Backup domain control register 			<0x20> */
    volatile uint32_t CSR;      /* Control/status register 					<0x24> */
} RCC_t;

#define RCC (*((RCC_t *)0x40021000))

#define CLK_SRC_HSI (0U)
#define CLK_SRC_HSE (1U)
#define CLK_SRC_PLL (2U)

#define AHB_PRESCALER_MASK 0x000000F0
#define AHB_PRESCALER_DIVIDED_BY_1 (0U)
#define AHB_PRESCALER_DIVIDED_BY_2 (8U)
#define AHB_PRESCALER_DIVIDED_BY_4 (9U)
#define AHB_PRESCALER_DIVIDED_BY_8 (10U)
#define AHB_PRESCALER_DIVIDED_BY_16 (11U)
#define AHB_PRESCALER_DIVIDED_BY_64 (12U)
#define AHB_PRESCALER_DIVIDED_BY_128 (13U)
#define AHB_PRESCALER_DIVIDED_BY_256 (14U)
#define AHB_PRESCALER_DIVIDED_BY_512 (15U)

#define APB1_PRESCALER_MASK 0x00000700
#define APB1_PRESCALER_DIVIDED_BY_1 (0U)
#define APB1_PRESCALER_DIVIDED_BY_2 (4U)
#define APB1_PRESCALER_DIVIDED_BY_4 (5U)
#define APB1_PRESCALER_DIVIDED_BY_8 (6U)
#define APB1_PRESCALER_DIVIDED_BY_16 (7U)

#define APB2_PRESCALER_MASK 0x00003800
#define APB2_PRESCALER_DIVIDED_BY_1 (0U)
#define APB2_PRESCALER_DIVIDED_BY_2 (4U)
#define APB2_PRESCALER_DIVIDED_BY_4 (5U)
#define APB2_PRESCALER_DIVIDED_BY_8 (6U)
#define APB2_PRESCALER_DIVIDED_BY_16 (7U)

#define ADC_PRESCALER_MASK 0x0000C000
#define ADC_PRESCALER_DIVIDED_BY_2 (0U)
#define ADC_PRESCALER_DIVIDED_BY_4 (1U)
#define ADC_PRESCALER_DIVIDED_BY_6 (2U)
#define ADC_PRESCALER_DIVIDED_BY_8 (3U)

#endif /* _RCC_PRIVATE_H_ */
