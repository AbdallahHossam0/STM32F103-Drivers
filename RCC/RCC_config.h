/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <RCC_config.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <07 - 01 - 2024>
 *
 * [DESCRIPTION]: <Reset and Clock Control Configuration Header File>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_

#include "RCC_private.h"

/* ==================================================== */
/* @CLK_SRC: This configures the clk src for the system */
/* ================= Available Options ================ */
/* ====== {CLK_SRC_HSI, CLK_SRC_HSE, CLK_SRC_PLL} ===== */
#define CLK_SRC CLK_SRC_HSI

/* ============================================================= */
/* ======= @AHB_PRESCALER: Defined the AHB CLK prescaler ======= */
/* ===================== Available Options ===================== */
/* = {AHB_PRESCALER_DIVIDED_BY_1, AHB_PRESCALER_DIVIDED_BY_2} == */
/* = {AHB_PRESCALER_DIVIDED_BY_4, AHB_PRESCALER_DIVIDED_BY_8} == */
/* = {AHB_PRESCALER_DIVIDED_BY_16, AHB_PRESCALER_DIVIDED_BY_64}  */
/*  {AHB_PRESCALER_DIVIDED_BY_128, AHB_PRESCALER_DIVIDED_BY_256} */
/* ============= {AHB_PRESCALER_DIVIDED_BY_512} ================ */
#define AHB_PRESCALER AHB_PRESCALER_DIVIDED_BY_1

/* ============================================================= */
/* ====== @APB1_PRESCALER: Defined the AHB CLK prescaler ======= */
/* ===================== Available Options ===================== */
/*   {APB1_PRESCALER_DIVIDED_BY_1, APB1_PRESCALER_DIVIDED_BY_2}  */
/*   {APB1_PRESCALER_DIVIDED_BY_4, APB1_PRESCALER_DIVIDED_BY_8}  */
/* ============= {APB1_PRESCALER_DIVIDED_BY_16} ================ */
#define APB1_PRESCALER APB1_PRESCALER_DIVIDED_BY_1

/* ============================================================= */
/* ====== @APB2_PRESCALER: Defined the AHB CLK prescaler ======= */
/* ===================== Available Options ===================== */
/*   {APB2_PRESCALER_DIVIDED_BY_1, APB2_PRESCALER_DIVIDED_BY_2}  */
/*   {APB2_PRESCALER_DIVIDED_BY_4, APB2_PRESCALER_DIVIDED_BY_8}  */
/* ============= {APB2_PRESCALER_DIVIDED_BY_16} ================ */
#define APB2_PRESCALER APB2_PRESCALER_DIVIDED_BY_1

/* ============================================================= */
/* ======= @ADC_PRESCALER: Defined the ADC CLK prescaler ======= */
/* ===================== Available Options ===================== */
/*  = {ADC_PRESCALER_DIVIDED_BY_2, ADC_PRESCALER_DIVIDED_BY_4} = */
/*  = {ADC_PRESCALER_DIVIDED_BY_6, ADC_PRESCALER_DIVIDED_BY_8} = */
#define ADC_PRESCALER ADC_PRESCALER_DIVIDED_BY_4

#endif /* _RCC_CONFIG_H_ */
