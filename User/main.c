#include "stm32f0xx.h"                  // Device header
#include "defines.h"
#include "delay.h"
#include "func.h"
#include "config.h"

#define FLAG_LEFT   (1<<0)
#define FLAG_RIGHT  (1<<1)
#define FLAG_LIGHT  (1<<2)
#define FLAG_BACK   (1<<3)
#define FLAG_STOP   (1<<4)
#define FLAG_WARN   (1<<5)
#define FLAG_STROB  (1<<6)

#define SYSFLAG_INT0 (1<<0)
#define SYSFLAG_INT1 (1<<1)

#define ACTION_IDLE    (1<<0)
#define ACTION_MEASURE (1<<1)
#define ACTION_UPDATE  (1<<2)
#define ACTION_BUTTON  (1<<3)

#define MODE_IDLE 0x01
#define MODE_STROB 0x02

uint8_t action, flag, mode = MODE_IDLE, sysflag, int0, int1;
uint32_t system_tick_counter, blinker_counter, warn_counter;


void EXTI0_1_IRQHandler(void) // Button interrupt routine
{
   EXTI->PR = 0x02; 
	if(!(GPIOB->IDR & (1<<1)))
	{
		delay_ms(debounce_time);
	}
	 if(!(GPIOB->IDR & (1<<1)))
	 {
		 mode++;
		 if(mode > num_modes) mode = MODE_IDLE;
	 }
}

void TIM17_IRQHandler(void)  // Update timer interrupt routine
{
	TIM17->SR = 0;
	system_tick_counter++;
	blinker_counter++;
	
	if(mode == MODE_IDLE)
	{
		if(flag & FLAG_STOP) TIM14->CCR1 = 47999;
		else TIM14->CCR1 = 15000;
		if(flag & FLAG_BACK) GPIOA->BSRR |= GPIO_BSRR_3_S;
		else GPIOA->BSRR |= GPIO_BSRR_3_R;
		
		if((flag & FLAG_STOP) || !(flag & FLAG_LEFT) || !(flag & FLAG_RIGHT)) warn_counter++;
		if(warn_counter > warn_time)
		{
			flag |= FLAG_WARN;
			warn_counter = 0;
		}
    if((!(flag & FLAG_STOP)) && (flag & FLAG_WARN)) flag &= ~FLAG_WARN;
		
		if(blinker_counter > blinker_time)
		{
			blinker_counter = 0;
			
			if((flag & FLAG_LEFT) || (flag & FLAG_WARN))
			{
				if(int0) GPIOA->BSRR |= GPIO_BSRR_1_S;
				else GPIOA->BSRR |= GPIO_BSRR_1_R;
				int0=!int0;       
			}
			else
			{
				GPIOA->BSRR |= GPIO_BSRR_1_R;
				int0 = 0;
			}
			
			if((flag & FLAG_RIGHT) || (flag & FLAG_WARN))
			{
				if(int1) GPIOA->BSRR |= GPIO_BSRR_2_S;
				else GPIOA->BSRR |= GPIO_BSRR_2_R;
				int1=!int1;       
			}
			else
			{
				GPIOA->BSRR |= GPIO_BSRR_2_R;
				int1 = 0;
			}
			
		}	
	}
}

int __attribute__((noreturn)) main(void)
{
	/* Local variables definition */
	uint16_t setup_th, setup_st;  // Initial calibration values will be stored here
	uint16_t cur_th, cur_st;      // Current channel duty value will be here
	/* -------------------------- */
	
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
	NVIC_EnableIRQ(EXTI0_1_IRQn);
	/* ---------- */
	
	/* Timers setup */
      /* TIM17 - update timer */
	    TIM17->PSC = 47;
	    TIM17->DIER |= TIM_DIER_UIE;
	    TIM17->CR1 |= TIM_CR1_CEN;
			NVIC_SetPriority(TIM17_IRQn, 1);
	    NVIC_EnableIRQ(TIM17_IRQn);
			/* -------------------- */
			
			/* TIM14 - PWM timer */
			TIM14->ARR = 48000-1;
      TIM14->CCMR1 |= TIM_CCMR1_OC1PE;
	    TIM14->CCMR1 |= (TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2);
	    TIM14->CCER |= TIM_CCER_CC1E;
	    TIM14->BDTR |= TIM_BDTR_MOE;
	    TIM14->CR1 |= TIM_CR1_CEN;
	    TIM14->CCR1 = 0;
			/* ----------------- */
			
			/* TIM1 - pulsein() timer */
			TIM1->PSC = 48-1;
			/* ---------------------- */
	/* ------------ */                                 
	    
	/* Initial calibration */
	while(pulsein(0) < 1000){}  // This delay is neccessary to wait for stable signal
	 setup_th = pulsein(0);
	while(pulsein(1) < 1000){}
	 setup_st = pulsein(1);
	/* ------------------- */
	while(1)
	{
		cur_th = pulsein(0);
		cur_st = pulsein(1);
		
		if(cur_th > (setup_th - hysteresis/2) || (cur_th < setup_th + hysteresis/2)) flag |= FLAG_STOP;
		else flag &= ~FLAG_STOP;
		if(reverse_th)
		{
			if(cur_th < (setup_th - hysteresis)) flag |= FLAG_BACK;
			else flag &= ~FLAG_BACK;
		}
		else
		{
			if(cur_th > (setup_th + hysteresis)) flag |= FLAG_BACK;
			else flag &= ~FLAG_BACK;
		}
		
		if(reverse_st)
		{
			if(cur_st > (setup_st + hysteresis/2)) flag |= FLAG_LEFT;
			else flag &= ~FLAG_LEFT;
			
			if(cur_st < (setup_st - hysteresis/2)) flag |= FLAG_RIGHT;
			else flag &= ~FLAG_RIGHT;
		}
		else
			{
			if(cur_st < (setup_st - hysteresis/2)) flag |= FLAG_LEFT;
			else flag &= ~FLAG_LEFT;
			
			if(cur_st > (setup_st + hysteresis/2)) flag |= FLAG_RIGHT;
			else flag &= ~FLAG_RIGHT;
		}
		

	}
}
