#include "stm32f0xx.h"                  // Device header
#include "defines.h"
#include "delay.h"
#include "func.h"


int __attribute__((noreturn)) main(void)
{
	/* ------------------------------------------------------------------ */
	system_clock();   // Initing PLL from 8MHz/2 HSI with x12 multiplier
	init_delay();     // Initing delay functions (using TIM2)
	/* ------------------------------------------------------------------ */
	
	/* RCC setup */
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOFEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN | RCC_APB1ENR_TIM14EN;
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN | RCC_APB2ENR_TIM17EN | RCC_APB2ENR_SYSCFGCOMPEN;
	/* --------- */
	
	/* GPIO setup */
	GPIOA->MODER |= GPIO_MODER_1_OUT | GPIO_MODER_2_OUT | GPIO_MODER_3_OUT | GPIO_MODER_5_OUT | GPIO_MODER_6_OUT;  // Generic LED outputs
	GPIOA->MODER |= GPIO_MODER_4_AF;                   // STOP LED output (supports PWM)
	GPIOA->MODER |= GPIO_MODER_7_AF;                   // WS2812B strip output
	GPIOB->MODER |= GPIO_MODER_1_IN;                   // Button input
	GPIOF->MODER |= GPIO_MODER_0_IN | GPIO_MODER_1_IN; // Signal inputs
	
	GPIOB->PUPDR |= GPIO_PUPDR_1_UP;                   // Pull up button pin
	GPIOF->PUPDR |= GPIO_PUPDR_0_DN | GPIO_PUPDR_1_DN; // Pull down signal inputs
	
	GPIOA_AFRL |= GPIO_AFRL_4_A4 | GPIO_AFRL_7_A0;     // Enabling alternative functions - A4 is TIM14_CH1 and A7 is SPI1_MOSI
	
	SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI1_PB;
	EXTI->IMR = EXTI_IMR_MR1 ;
	EXTI->FTSR = EXTI_FTSR_TR1 ;
//	NVIC_EnableIRQ(EXTI0_1_IRQn);
	/* ---------- */
	
	/* Timers setup */
      /* TIM17 - update timer */
	    TIM17->PSC = 47;
	    TIM17->DIER |= TIM_DIER_UIE;
	    TIM17->CR1 |= TIM_CR1_CEN;
			NVIC_SetPriority(TIM17_IRQn, 1);
	 //   NVIC_EnableIRQ(TIM17_IRQn);
			/* -------------------- */
			
			/* TIM14 - PWM timer */
			TIM14->ARR = 48000-1;
      TIM14->CCMR1 |= TIM_CCMR1_OC1PE;
	    TIM14->CCMR1 |= (TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2);
	    TIM14->CCER |= TIM_CCER_CC1E;
	    TIM14->BDTR |= TIM_BDTR_MOE;
	    TIM14->CR1 |= TIM_CR1_CEN;
	    TIM14->CCR1 = 47999;
			/* ----------------- */
			
			/* TIM1 - pulsein() timer */
			TIM1->PSC = 48-1;
			/* ---------------------- */
	/* ------------ */                                 
	TIM14->CCR1  =0;                                                                                                                                                                                                                                               
	
	while(1)
	{
		
	}
}
