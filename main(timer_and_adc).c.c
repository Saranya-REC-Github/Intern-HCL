#include "stm32f4xx.h"

// Function prototypes
void GPIO_Init(void);
void ADC1_Init(void);
void TIM2_Init(void);
uint16_t ADC_Read(void);
void delay_ms(uint32_t ms);

//---------------------------------------

int main(void)
{
    GPIO_Init();
    ADC1_Init();
    TIM2_Init();

    while (1)
    {
        // Wait for TIM2 update event (500 ms)
        while (!(TIM2->SR & TIM_SR_UIF));
        TIM2->SR &= ~TIM_SR_UIF; // Clear flag

        uint16_t adc_val = ADC_Read();

        // Convert ADC value to voltage
        float voltage = (adc_val * 3.3f) / 4095.0f;

        if (voltage < 2.0f)   // ✅ Better threshold
        {
            // Fast blinking
            for (int i = 0; i < 5; i++)
            {
                GPIOD->ODR ^= (1 << 14); // Toggle PD14
                delay_ms(100);
            }
        }
        else
        {
            GPIOD->ODR &= ~(1 << 14); // LED OFF
        }
    }
}

//---------------------------------------
// GPIO Initialization
void GPIO_Init(void)
{
    // Enable clocks
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

    // PA1 as Analog
    GPIOA->MODER |= (3 << (1 * 2));

    // PD14 as Output
    GPIOD->MODER &= ~(3 << (14 * 2)); // Clear
    GPIOD->MODER |= (1 << (14 * 2));  // Output
}

//---------------------------------------
// ADC1 Initialization
void ADC1_Init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    ADC->CCR |= (1 << 16); // Prescaler /4

    ADC1->SMPR2 |= (7 << 3); // Channel 1 sampling

    ADC1->SQR1 = 0;  // 1 conversion
    ADC1->SQR3 = 1;  // Channel 1

    ADC1->CR2 |= ADC_CR2_ADON;
}

//---------------------------------------
// Timer2 Initialization (500 ms)
void TIM2_Init(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    TIM2->PSC = 16000 - 1;  // 1 kHz
    TIM2->ARR = 500 - 1;    // 500 ms

    TIM2->CR1 |= TIM_CR1_CEN;
}

//---------------------------------------
// ADC Read
uint16_t ADC_Read(void)
{
    ADC1->CR2 |= ADC_CR2_SWSTART;

    while (!(ADC1->SR & ADC_SR_EOC));

    return ADC1->DR;
}

//---------------------------------------
// Simple delay (approx)
void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 4000; i++)
    {
        __NOP();
    }
}
