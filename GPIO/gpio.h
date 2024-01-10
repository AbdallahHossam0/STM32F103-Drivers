/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <GPIO.h here>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <10 - 01 - 2024>
 *
 * [DESCRIPTION]: <Header file for GPIO Driver of the stm32f103>
 * ---------------------------------------------------------------------------------------------------
 */


#ifndef HAL_DRIVERS_GPIO_GPIO_H_
#define HAL_DRIVERS_GPIO_GPIO_H_

#include <stdint.h>

#define GPIO_A_BASE_ADDRESS		0x40010800

#define GPIO_B_BASE_ADDRESS		0x40010C00

#define GPIO_C_BASE_ADDRESS		0x40011000

#define BIT_MASK 				0x0000000F

typedef struct{
	volatile uint32_t CRL;			// <offset: 0x00>:	Port configuration register LOW
	volatile uint32_t CRH;			// <offset: 0x04>:	Port configuration register HIGH
	volatile uint32_t IDR;			// <offset: 0x08>:	Port input data register
	volatile uint32_t ODR;			// <offset: 0x0C>:	Port output data register
	volatile uint32_t BSRR;			// <offset: 0x10>:	Port bit set/reset register
	volatile uint32_t BRR;			// <offset: 0x14>:	Port bit reset register
	volatile uint32_t LCKR;			// <offset: 0x18>:	Port configuration lock register
}GPIO_REGS_t;

#define GPIO_A		(*(GPIO_REGS_t*) GPIO_A_BASE_ADDRESS)
#define GPIO_B		(*(GPIO_REGS_t*) GPIO_B_BASE_ADDRESS)
#define GPIO_C		(*(GPIO_REGS_t*) GPIO_C_BASE_ADDRESS)

typedef enum{
	GPIOA,
	GPIOB,
	GPIOC
}GPIO_t;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
}Pin_t;

typedef enum{
  GPIO_SPEED_10MHz = 1,
  GPIO_SPEED_2MHz,
  GPIO_SPEED_50MHz
}GPIO_PinSpeed_t;

typedef enum{
	ANALOG_INPUT,
	DIGITAL_INPUT_FLOATING,
	DIGITAL_INPUT_WITH_PULL_UP,
	DIGITAL_INPUT_WITH_PULL_DOWN,
	DIGITAL_OUTPUT_PUSH_PULL,
	DIGITAL_OUTPUT_OPEN_DRAIN,
	ALT_FUNC_PUSH_PULL,
	ALT_FUNC_OPEN_DRAIN
}GPIO_PinMode_t;

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	GPIO_clockInit
 *
 * [DESCRIPTION]:	Function to enable the clock for the GPIO Module
 *
 * [Args]:			GPIOx(GPIO_t)
 *
 * [IN]:			GPIOx(GPIO_t): Port you want to enable the clock for.
 * 					Possible values: 	GPIOA, GPIOB, GPIOC
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void GPIO_clockInit(GPIO_t GPIOx);


/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	GPIO_clockDeInit
 *
 * [DESCRIPTION]:	Function to disable the clock for the GPIO Module
 *
 * [Args]:			GPIOx(GPIO_t)
 *
 * [IN]:			GPIOx(GPIO_t): Port you want to disable the clock for.
 * 					Possible values: 	GPIOA, GPIOB, GPIOC
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void GPIO_clockDeInit(GPIO_t GPIOx);

void GPIO_AFIO_clockInit(void);
void GPIO_AFIO_clockDeInit(void);

/* Function Comment
 * ---------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]:	GPIO_pinInit
 *
 * [DESCRIPTION]:	Function to setup the pin
 *
 * [Args]:			GPIOx(GPIO_t), pin(Pin_t), mode(GPIO_PinMode_t), speed(GPIO_PinSpeed_t)
 *
 * [IN]:			GPIOx: port name
 * 					pin: pin number
 * 					mode: mode you need ref @GPIO_PinMode_t
 * 					speed: speed in the case of the output, incase if the input enter 0
 *
 * [OUT]:			None
 *
 * [IN / OUT]:		None
 *
 * [RETURNS]:		void
 * ---------------------------------------------------------------------------------------------------
 */
void GPIO_pinInit(GPIO_t GPIOx, Pin_t pin, GPIO_PinMode_t mode, GPIO_PinSpeed_t speed);

uint8_t GPIO_pinRead(GPIO_t GPIOx, Pin_t pin);
uint16_t GPIO_read(GPIO_t GPIOx);
void GPIO_pinSet(GPIO_t GPIOx, Pin_t pin);
void GPIO_pinReset(GPIO_t GPIOx, Pin_t pin);
void GPIO_pinToggle(GPIO_t GPIOx, Pin_t pin);
void GPIO_pinWrite(GPIO_t GPIOx, Pin_t pin, uint8_t level);

void GPIO_write(GPIO_t GPIOx, uint16_t value);


void GPIO_pinLock(GPIO_t GPIOx, Pin_t pin);


/* --- To Be Implemented Later ---*/
void GPIO_EXTI_lineCfg(GPIO_t GPIOx, Pin_t pin);
void GPIO_setAlternativeFunction(GPIO_t GPIOx, Pin_t pin);




#endif /* HAL_DRIVERS_GPIO_GPIO_H_ */
