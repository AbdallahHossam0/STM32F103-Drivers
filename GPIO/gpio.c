/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <gpio.c>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosny
 *
 * [DATE CREATED]: <10 - 01 - 2024>
 *
 * [DESCRIPTION]: <Source file for GPIO Driver of the stm32f103>
 * ---------------------------------------------------------------------------------------------------
 */
#include "HAL_Drivers/GPIO/gpio.h"
#include "HAL_Drivers/RCC/RCC.h"

void GPIO_clockInit(GPIO_t GPIOx){
	switch(GPIOx){
	case GPIOA:
		RCC_GPIOA_CLK_ENABLE();
		break;
	case GPIOB:
		RCC_GPIOB_CLK_ENABLE();
		break;
	case GPIOC:
		RCC_GPIOC_CLK_ENABLE();
		break;
	default:
		break;
	}
}

void GPIO_clockDeInit(GPIO_t GPIOx){
	switch(GPIOx){
	case GPIOA:
		RCC_GPIOA_CLK_DISABLE();
		break;
	case GPIOB:
		RCC_GPIOB_CLK_DISABLE();
		break;
	case GPIOC:
		RCC_GPIOC_CLK_DISABLE();
		break;
	default:
		break;
	}
}

void GPIO_AFIO_clockInit(void){
	RCC_AFIO_CLK_ENABLE();
}

void GPIO_AFIO_clockDeInit(void){
	RCC_AFIO_CLK_DISABLE();
}

void GPIO_pinInit(GPIO_t GPIOx, Pin_t pin, GPIO_PinMode_t mode, GPIO_PinSpeed_t speed){
	uint8_t cfg = 0;
	uint8_t flag = 0;
	if(pin > 7){
		flag = 1;
		pin -= 8;
	}
	switch(GPIOx){
	case GPIOA:
		if(flag){
			GPIO_A.CRH &= ~(BIT_MASK << (pin << 2));
		}
		else{
			GPIO_A.CRL &= ~(BIT_MASK << (pin << 2));
		}
		switch(mode){
		case ANALOG_INPUT:
			break;
		case DIGITAL_INPUT_FLOATING:
			SET_BIT(cfg, 2);
			break;
		case DIGITAL_INPUT_WITH_PULL_UP:
			SET_BIT(cfg, 3);
			SET_BIT(GPIO_A.ODR, pin);
			break;
		case DIGITAL_INPUT_WITH_PULL_DOWN:
			SET_BIT(cfg, 3);
			CLEAR_BIT(GPIO_A.ODR, pin);
			break;
		case DIGITAL_OUTPUT_PUSH_PULL:
			cfg |= speed;
			break;
		case DIGITAL_OUTPUT_OPEN_DRAIN:
			SET_BIT(cfg, 2);
			cfg |= speed;
			break;
		case ALT_FUNC_PUSH_PULL:
			SET_BIT(cfg,3);
			cfg |= speed;
			break;
		case ALT_FUNC_OPEN_DRAIN:
			SET_BIT(cfg,3);
			SET_BIT(cfg,2);
			cfg |= speed;
			break;
		default: break;
		}
		if(flag){
			GPIO_A.CRH |= (cfg & 0x0F) << (pin << 2);
		}
		else{
			GPIO_A.CRL |= (cfg & 0x0F) << (pin << 2);
		}
		break;
	case GPIOB:
		if(flag){
			GPIO_B.CRH &= ~(BIT_MASK << (pin << 2));
		}
		else{
			GPIO_B.CRL &= ~(BIT_MASK << (pin << 2));
		}
		switch(mode){
		case ANALOG_INPUT:
			break;
		case DIGITAL_INPUT_FLOATING:
			SET_BIT(cfg, 2);
			break;
		case DIGITAL_INPUT_WITH_PULL_UP:
			SET_BIT(cfg, 3);
			SET_BIT(GPIO_B.ODR, pin);
			break;
		case DIGITAL_INPUT_WITH_PULL_DOWN:
			SET_BIT(cfg, 3);
			CLEAR_BIT(GPIO_B.ODR, pin);
			break;
		case DIGITAL_OUTPUT_PUSH_PULL:
			cfg |= speed;
			break;
		case DIGITAL_OUTPUT_OPEN_DRAIN:
			SET_BIT(cfg, 2);
			cfg |= speed;
			break;
		case ALT_FUNC_PUSH_PULL:
			SET_BIT(cfg,3);
			cfg |= speed;
			break;
		case ALT_FUNC_OPEN_DRAIN:
			SET_BIT(cfg,3);
			SET_BIT(cfg,2);
			cfg |= speed;
			break;
		default: break;
		}
		if(flag){
			GPIO_B.CRH |= (cfg & 0x0F) << (pin << 2);
		}
		else{
			GPIO_B.CRL |= (cfg & 0x0F) << (pin << 2);
		}
		break;
	case GPIOC:
		if(flag){
			GPIO_C.CRH &= ~(BIT_MASK << (pin << 2));
		}
		else{
			pin -= 8;
			GPIO_C.CRL &= ~(BIT_MASK << (pin << 2));
		}
		switch(mode){
		case ANALOG_INPUT:
			break;
		case DIGITAL_INPUT_FLOATING:
			SET_BIT(cfg, 2);
			break;
		case DIGITAL_INPUT_WITH_PULL_UP:
			SET_BIT(cfg, 3);
			SET_BIT(GPIO_C.ODR, pin);
			break;
		case DIGITAL_INPUT_WITH_PULL_DOWN:
			SET_BIT(cfg, 3);
			CLEAR_BIT(GPIO_C.ODR, pin);
			break;
		case DIGITAL_OUTPUT_PUSH_PULL:
			cfg |= speed;
			break;
		case DIGITAL_OUTPUT_OPEN_DRAIN:
			SET_BIT(cfg, 2);
			cfg |= speed;
			break;
		case ALT_FUNC_PUSH_PULL:
			SET_BIT(cfg,3);
			cfg |= speed;
			break;
		case ALT_FUNC_OPEN_DRAIN:
			SET_BIT(cfg,3);
			SET_BIT(cfg,2);
			cfg |= speed;
			break;
		default: break;
		}
		if(flag){
			GPIO_C.CRH |= (cfg & 0x0F) << (pin << 2);
		}
		else{
			GPIO_C.CRL |= (cfg & 0x0F) << (pin << 2);
		}
		break;
	default:
		break;
	}
}


uint8_t GPIO_pinRead(GPIO_t GPIOx, Pin_t pin){
	uint8_t pinLevel;
	switch(GPIOx){
	case GPIOA:
		pinLevel = BIT_IS_SET(GPIO_A.IDR, pin) ? 1 : 0;
		break;
	case GPIOB:
		pinLevel = BIT_IS_SET(GPIO_B.IDR, pin) ? 1 : 0;
		break;
	case GPIOC:
		pinLevel = BIT_IS_SET(GPIO_C.IDR, pin) ? 1 : 0;
		break;
	}
	return pinLevel;
}

uint16_t GPIO_read(GPIO_t GPIOx){
	uint16_t portLevel;
	switch(GPIOx){
	case GPIOA:
		portLevel = GPIO_A.IDR;
		break;
	case GPIOB:
		portLevel = GPIO_B.IDR;
		break;
	case GPIOC:
		portLevel = GPIO_C.IDR;
		break;
	}
	return portLevel;
}


void GPIO_pinSet(GPIO_t GPIOx, Pin_t pin){
	switch(GPIOx){
	case GPIOA:
		SET_BIT(GPIO_A.ODR, pin);
		break;
	case GPIOB:
		SET_BIT(GPIO_B.ODR, pin);
		break;
	case GPIOC:
		SET_BIT(GPIO_C.ODR, pin);
		break;
	}
}

void GPIO_pinReset(GPIO_t GPIOx, Pin_t pin){
	switch(GPIOx){
	case GPIOA:
		CLEAR_BIT(GPIO_A.ODR, pin);
		break;
	case GPIOB:
		CLEAR_BIT(GPIO_B.ODR, pin);
		break;
	case GPIOC:
		CLEAR_BIT(GPIO_C.ODR, pin);
		break;
	}
}

void GPIO_pinToggle(GPIO_t GPIOx, Pin_t pin){
	switch(GPIOx){
	case GPIOA:
		TOGGLE_BIT(GPIO_A.ODR, pin);
		break;
	case GPIOB:
		TOGGLE_BIT(GPIO_B.ODR, pin);
		break;
	case GPIOC:
		TOGGLE_BIT(GPIO_C.ODR, pin);
		break;
	}
}

void GPIO_pinWrite(GPIO_t GPIOx, Pin_t pin, uint8_t level){
	if(level){
		GPIO_pinSet(GPIOx, pin);
	}
	else{
		GPIO_pinReset(GPIOx, pin);
	}
}


void GPIO_write(GPIO_t GPIOx, uint16_t value){
	switch(GPIOx){
	case GPIOA:
		GPIO_A.ODR = value;
		break;
	case GPIOB:
		GPIO_B.ODR = value;
		break;
	case GPIOC:
		GPIO_C.ODR = value;
		break;
	}
}



void GPIO_pinLock(GPIO_t GPIOx, Pin_t pin){
	uint32_t val = 1 << 16 | 1 << pin;
	switch(GPIOx){
	case GPIOA:
		GPIO_A.LCKR = val;
		GPIO_A.LCKR = pin;
		GPIO_A.LCKR = val;
		val = GPIO_A.LCKR;
		val = GPIO_A.LCKR;
		break;
	case GPIOB:
		GPIO_B.LCKR = val;
		GPIO_B.LCKR = pin;
		GPIO_B.LCKR = val;
		val = GPIO_B.LCKR;
		val = GPIO_B.LCKR;
		break;
	case GPIOC:
		GPIO_C.LCKR = val;
		GPIO_C.LCKR = pin;
		GPIO_C.LCKR = val;
		val = GPIO_C.LCKR;
		val = GPIO_C.LCKR;
		break;
	}
}
