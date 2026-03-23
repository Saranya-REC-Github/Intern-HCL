#include "stm32f4xx.h"

void GPIO_Init(void);
void TIM4_PWM_Init(void);
void set_servo1_angle(float angle);
void set_servo2_angle(float angle);
void delay_ms(uint32_t ms);

int main(void)
{
    GPIO_Init();
    TIM4_PWM_Init();

    while (1)
    {
        set_servo1_angle(0);
        set_servo2_angle(0);
        delay_ms(1000);

        set_servo1_angle(90);
        set_servo2_angle(90);
        delay_ms(1000);

        set_servo1_angle(180);
        set_servo2_angle(180);
        delay_ms(1000);
    }
}

// GPIO Configuration (PB8, PB9 → TIM4)
void GPIO_Init(void)
{
    // Enable GPIOB clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    // Set PB8, PB9 as Alternate Function
    GPIOB->MODER &= ~((3 << (8 * 2)) | (3 << (9 * 2)));
    GPIOB->MODER |= (2 << (8 * 2)) | (2 << (9 * 2));

    // Set AF2 (TIM4)
    GPIOB->AFR[1] &= ~((0xF << ((8 - 8) * 4)) | (0xF << ((9 - 8) * 4)));
    GPIOB->AFR[1] |= (2 << ((8 - 8) * 4)) | (2 << ((9 - 8) * 4));
}

// TIM4 PWM Initialization (50 Hz for Servo)
void TIM4_PWM_Init(void)
{
    // Enable TIM4 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

    // 16 MHz / 16 = 1 MHz (1 µs resolution)
    TIM4->PSC = 16 - 1;

    // 20 ms period → 50 Hz
    TIM4->ARR = 20000 - 1;

    // PWM Mode 1 for CH3 & CH4
    TIM4->CCMR2 &= ~((7 << 4) | (7 << 12));
    TIM4->CCMR2 |= (6 << 4) | (6 << 12);

    // Enable preload
    TIM4->CCMR2 |= (1 << 3) | (1 << 11);

    // Enable channels CH3 & CH4
    TIM4->CCER |= TIM_CCER_CC3E | TIM_CCER_CC4E;

    // Initial pulse (center)
    TIM4->CCR3 = 1500;
    TIM4->CCR4 = 1500;

    // Enable auto-reload preload
    TIM4->CR1 |= TIM_CR1_ARPE;

    // Force update
    TIM4->EGR |= TIM_EGR_UG;

    // Start timer
    TIM4->CR1 |= TIM_CR1_CEN;
}

// Servo 1 (PB8 → CH3)
void set_servo1_angle(float angle)
{
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;

    uint16_t pulse = 1000 + (angle * (1000.0 / 180.0));
    TIM4->CCR3 = pulse;
}

// Servo 2 (PB9 → CH4)
void set_servo2_angle(float angle)
{
    if (angle < 0) angle = 0;
    if (angle > 180) angle = 180;

    uint16_t pulse = 1000 + (angle * (1000.0 / 180.0));
    TIM4->CCR4 = pulse;
}

// Delay
void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 4000; i++);
}
