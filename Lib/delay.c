#include <stm32f0xx.h>
#include "defines.h"
#include "delay.h"




void init_delay(void)
{
 RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
}
void delay_ms(uint16_t delay)
{
	TIM2_PSC = 48000000 / 1000 + 1; 
  TIM2_ARR = delay; 
  TIM2_EGR |= TIM_EGR_UG; 
  TIM2_CR1 |= TIM_CR1_CEN | TIM_CR1_OPM; 
    while ((TIM2_CR1 & TIM_CR1_CEN) != 0);
}
	
void delay_us(uint16_t delay)
{
	TIM1->PSC = 8000000 / 1000000 + 1; 
  TIM1->ARR = delay; 
  TIM1->EGR |= TIM_EGR_UG; 
  TIM1->CR1 |= TIM_CR1_CEN | TIM_CR1_OPM; 
    while ((TIM1->CR1 & TIM_CR1_CEN) != 0);
}

void delay_ws(uint16_t delay)
{
	TIM1->PSC = 0;
  TIM1->ARR = delay; 
  TIM1->EGR |= TIM_EGR_UG; 
  TIM1->CR1 |= TIM_CR1_CEN | TIM_CR1_OPM; 
    while ((TIM1->CR1 & TIM_CR1_CEN) != 0);
}

void system_clock(void)
{
	if ((RCC->CFGR & RCC_CFGR_SWS) == RCC_CFGR_SWS_PLL)
{          
  RCC->CFGR &= (uint32_t) (~RCC_CFGR_SW);
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
}
RCC->CR &= (uint32_t)(~RCC_CR_PLLON);    
while((RCC->CR & RCC_CR_PLLRDY) != 0);
RCC->CFGR = RCC->CFGR & (~RCC_CFGR_PLLMUL) | (RCC_CFGR_PLLMUL12);
RCC->CR |= RCC_CR_PLLON;
while((RCC->CR & RCC_CR_PLLRDY) == 0);
RCC->CFGR |= (uint32_t) (RCC_CFGR_SW_PLL);
while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

}




