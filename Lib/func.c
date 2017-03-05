#include "stm32f0xx.h"                  // Device header
#include "defines.h"
#include "delay.h"
#include "func.h"


uint16_t pulsein (uint8_t pin)
{
	uint16_t result;
	while(GPIOF->IDR & (1<<pin));
	while(!(GPIOF->IDR & (1<<pin)));
	TIM1->CNT = 0;
	TIM1->CR1 |= TIM_CR1_CEN;
	while(GPIOF->IDR & (1<<pin));
	TIM1->CR1 &= ~(TIM_CR1_CEN);
	result = TIM1->CNT;
	
	TIM1->CNT = 0;
	return result;
}
