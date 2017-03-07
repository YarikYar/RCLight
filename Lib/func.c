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



void writeSPI(uint8_t *Data,unsigned Count)
{   
    while(Count--)
    {
        SPI1->DR = (uint8_t)(*Data);        
        Data++;        
        while  (SPI1->SR & SPI_SR_BSY); // wait if FIFO is full
    }    
}

void writeWS2812BA(uint32_t *val, uint8_t num)
{
	uint8_t SPI_DataT[9*num+1];
	uint32_t pointer =0;
	for(uint8_t i = 0; i < num; i++)
	{
		uint32_t Value = val[i];
	   uint32_t Encoding=0;
	
    int Index;
	
			
    // Process the GREEN byte
    Index=0;
    Encoding=0;
    while (Index < 8)
    {
        Encoding = Encoding << 3;
        if (Value & (1<<23))
        {
            Encoding |= 6;
        }
        else
        {
            Encoding |= 4;
        }
        Value = Value << 1;
        Index++;
        
    }  		
		pointer = 9*i;
		//if(pointer>8) pointer++;
    SPI_DataT[pointer++] = ((Encoding >> 16) & 0xff);
    SPI_DataT[pointer++] = ((Encoding >> 8) & 0xff);
    SPI_DataT[pointer++] = (Encoding & 0xff);
    
    // Process the RED byte
    Index=0;
    Encoding=0;
    while (Index < 8)
    {
        Encoding = Encoding << 3;
        if (Value & (1<<23))
        {
            Encoding |= 6;
        }
        else
        {
            Encoding |= 4;
        }
        Value = Value << 1;
        Index++;
        
    }    
    SPI_DataT[pointer++] = ((Encoding >> 16) & 0xff);
    SPI_DataT[pointer++] = ((Encoding >> 8) & 0xff);
    SPI_DataT[pointer++] = (Encoding & 0xff);
    
    // Process the BLUE byte
    Index=0;
    Encoding=0;
    while (Index < 8)
    {
        Encoding = Encoding << 3;
        if (Value & (1<<23))
        {
            Encoding |= 6;
        }
        else
        {
            Encoding |= 4;
        }
        Value = Value << 1;
        Index++;
        
    }    
    SPI_DataT[pointer++] = ((Encoding >> 16) & 0xff);
    SPI_DataT[pointer++] = ((Encoding >> 8) & 0xff);
    SPI_DataT[pointer++] = (Encoding & 0xff);
   
	}
	writeSPI(SPI_DataT,9*num+1);
}
