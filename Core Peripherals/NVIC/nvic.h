/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <nvic.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <23 - 01 - 2024>
 *
 * [DESCRIPTION]: <Header File for Cortex-M3 Core NVIC peripheral>
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef _NVIC_H_
#define _NVIC_H_

#include <stdint.h>

/* Base Address of the Nested Vectored Interrupt Controller (NVIC) */
#define NVIC_BASE_ADDRESS 0xE000E100UL

/* Access structure for the Nested Vectored Interrupt Controller (NVIC) */
#define NVIC (*((NVIC_t*)NVIC_BASE_ADDRESS))

/* Structure definition of the Nested Vectored Interrupt Controller (NVIC) */
typedef struct {
    volatile uint32_t ISER[8U]; /*!< Interrupt Set Enable Register */
    uint32_t Reserved0[24U];    /*!< Reserved */
    volatile uint32_t ICER[8U]; /*!< Interrupt Clear Enable Register */
    uint32_t Reserved1[24U];    /*!< Reserved */
    volatile uint32_t ISPR[8U]; /*!< Interrupt Set Pending Register */
    uint32_t Reserved2[24U];    /*!< Reserved */
    volatile uint32_t ICPR[8U]; /*!< Interrupt clear Pending Register */
    uint32_t Reserved3[24U];    /*!< Reserved */
    volatile uint32_t IABR[8U]; /*!< Interrupt Active Bit Register */
    uint32_t Reserved4[56U];    /*!< Reserved */
    volatile uint8_t IPR[240U]; /*!< Interrupt Priority Register */
    uint32_t Reserved5[644U];   /*!< Reserved */
    volatile uint32_t STIR;     /*!< Software Trigger Interrupt Register */
} NVIC_t;

// Enum Contains all available interrupts
typedef enum {
    // ----------------------- Cortex-Mx Processor Exceptions -----------------------
    NON_MASK_INT_IRQ = -14,      /* NMI Handler */
    HARD_FAULT_IRQ = -13,        /* Hard Fault Handler */
    MEMORY_MANAGEMENT_IRQ = -12, /* MPU Fault Handler */
    BUS_FAULT_IRQ = -11,         /* Bus Fault Handler */
    USAGE_FAULT_IRQ = -10,       /* Usage Fault Handler */
    SVCALL_IRQ = -5,             /* SVCall Handler */
    DEBUG_MONITOR_IRQ = -4,      /* Debug Monitor Handler */
    PENDSV_IRQ = -2,             /* PendSV Handler */
    SYSTICK_IRQ = -1,            /* SysTick Handler */
    // ----------------------- STM32F103 Specific Interrupts -----------------------
    WWDG_IRQ = 0,             /* 0: Window Watchdog */
    PVD_IRQ = 1,              /* 1: PVD through EXTI Line detect */
    TAMPER_IRQ = 2,           /* 2: Tamper */
    RTC_WKUP_IRQ = 3,         /* 3: RTC */
    FLASH_IRQ = 4,            /* 4: Flash */
    RCC_IRQ = 5,              /* 5: RCC */
    EXTI0_IRQ = 6,            /* 6: EXTI Line 0 */
    EXTI1_IRQ = 7,            /* 7: EXTI Line 1 */
    EXTI2_IRQ = 8,            /* 8: EXTI Line 2 */
    EXTI3_IRQ = 9,            /* 9: EXTI Line 3 */
    EXTI4_IRQ = 10,           /* 10: EXTI Line 4 */
    DMA1_CHANNEL1_IRQ = 11,   /* 11: DMA1 Channel 1 */
    DMA1_CHANNEL2_IRQ = 12,   /* 12: DMA1 Channel 2 */
    DMA1_CHANNEL3_IRQ = 13,   /* 13: DMA1 Channel 3 */
    DMA1_CHANNEL4_IRQ = 14,   /* 14: DMA1 Channel 4 */
    DMA1_CHANNEL5_IRQ = 15,   /* 15: DMA1 Channel 5 */
    DMA1_CHANNEL6_IRQ = 16,   /* 16: DMA1 Channel 6 */
    DMA1_CHANNEL7_IRQ = 17,   /* 17: DMA1 Channel 7 */
    ADC1_2_IRQ = 18,          /* 18: ADC1 & ADC2 */
    USB_HP_CAN1_TX_IRQ = 19,  /* 19: USB High Priority or CAN1 TX */
    USB_LP_CAN1_RX0_IRQ = 20, /* 20: USB Low  Priority or CAN1 RX0 */
    CAN1_RX1_IRQ = 21,        /* 21: CAN1 RX1 */
    CAN1_SCE_IRQ = 22,        /* 22: CAN1 SCE */
    EXTI9_5_IRQ = 23,         /* 23: EXTI Line 9..5 */
    TIM1_BRK_IRQ = 24,        /* 24: TIM1 Break */
    TIM1_UP_IRQ = 25,         /* 25: TIM1 Update */
    TIM1_TRG_COM_IRQ = 26,    /* 26: TIM1 Trigger and Commutation */
    TIM1_CC_IRQ = 27,         /* 27: TIM1 Capture Compare */
    TIM2_IRQ = 28,            /* 28: TIM2 */
    TIM3_IRQ = 29,            /* 29: TIM3 */
    TIM4_IRQ = 30,            /* 30: TIM4 */
    I2C1_EV_IRQ = 31,         /* 31: I2C1 Event */
    I2C1_ER_IRQ = 32,         /* 32: I2C1 Error */
    I2C2_EV_IRQ = 33,         /* 33: I2C2 Event */
    I2C2_ER_IRQ = 34,         /* 34: I2C2 Error */
    SPI1_IRQ = 35,            /* 35: SPI1 */
    SPI2_IRQ = 36,            /* 36: SPI2 */
    USART1_IRQ = 37,          /* 37: USART1 */
    USART2_IRQ = 38,          /* 38: USART2 */
    USART3_IRQ = 39,          /* 39: USART3 */
    EXTI15_10_IRQ = 40,       /* 40: EXTI Line 15..10 */
    RTC_Alarm_IRQ = 41,       /* 41: RTC Alarm through EXTI Line */
    USBWakeUp_IRQ = 42,       /* 42: USB Wakeup from suspend */
} IRQ_t;

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: NVIC_EnableIRQ
 *
 * [DESCRIPTION]:	Function to Enable an asynchronous Interrupt
 *
 * [Args]:			IRQn(IRQ_t)
 * 
 * [IN]:			IRQn(IRQ_t) contains the Name of the Interrupt you need to Enable from the type => IRQ_t
 * 
 * [OUT]:			None
 * 
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void NVIC_EnableIRQ(IRQ_t IRQn);

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: NVIC_DisableIRQ
 *
 * [DESCRIPTION]:	Function to Disable an asynchronous Interrupt
 *
 * [Args]:			IRQn(IRQ_t)
 * 
 * [IN]:			IRQn(IRQ_t) contains the Name of the Interrupt you need to Disable from the type => IRQ_t
 * 
 * [OUT]:			None
 * 
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void NVIC_DisableIRQ(IRQ_t IRQn);

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: NVIC_SetPendingIRQ
 *
 * [DESCRIPTION]:	Function to make an asynchronous Interrupt in the pending state
 *
 * [Args]:			IRQn(IRQ_t)
 * 
 * [IN]:			IRQn(IRQ_t) contains the Name of the Interrupt you need to pend from the type => IRQ_t
 * 
 * [OUT]:			None
 * 
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void NVIC_SetPendingIRQ(IRQ_t IRQn);

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: NVIC_ClearPendingIRQ
 *
 * [DESCRIPTION]:	Function to make an asynchronous Interrupt out the pending state
 *
 * [Args]:			IRQn(IRQ_t)
 * 
 * [IN]:			IRQn(IRQ_t) contains the Name of the Interrupt you need to un-pend from the type => IRQ_t
 * 
 * [OUT]:			None
 * 
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void NVIC_ClearPendingIRQ(IRQ_t IRQn);

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: NVIC_GetActive
 *
 * [DESCRIPTION]:	Function to return if the passed interrupt is active or not
 *
 * [Args]:			IRQn(IRQ_t)
 * 
 * [IN]:			IRQn(IRQ_t) contains the Name of the Interrupt you need to check is it active or not
 * 					Usually useful in case of Interrupt Nesting and Resource Handle
 * 					from the type => IRQ_t
 * 
 * [OUT]:			None
 * 
 * [IN / OUT]:		None
 *
 * [RETURNS]:		0: if the passed interrupt is not active, value: if the passed interrupt is active
 * ---------------------------------------------------------------------------------------------------
 */
uint8_t NVIC_GetActive(IRQ_t IRQn);


/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	NVIC_setPriority
 *
 * [DESCRIPTION]:	Function to set the priority level of the passed interrupt
 * 					You should use SCB_setPriorityGrouping Function before using it
 * 					and you have to pass the value of the group and sub group you need to set
 *
 * [Args]:			IRQn(IRQ_t), priority(uint8_t)
 *
 * [IN]:			IRQn(IRQ_t) contains the Name of the Interrupt you need to set the priority
 * 					for it from the type => IRQ_t
 * 					priority(uint8_t) contains the priority (group|subgroup)
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void NVIC_setPriority(IRQ_t IRQn, uint8_t priority);

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	NVIC_getPriority
 *
 * [DESCRIPTION]:	Function to get the priority of the passed interrupt name
 *
 * [Args]:			IRQn(IRQ_t)
 *
 * [IN]:			IRQn(IRQ_t) contains the Name of the Interrupt you need to get its priority
 * 					from the type => IRQ_t
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		The priority of the given interrupt
 * ---------------------------------------------------------------------------------------------------
 */
uint8_t NVIC_getPriority(IRQ_t IRQn);

#endif /* _NVIC_H_ */
