#include <stdint.h>

/* Base addresses */
#define RCC_BASE        0x40023800
#define GPIOD_BASE      0x40020C00

/* Register definitions */
#define RCC_AHB1ENR     (*(volatile unsigned int *)(RCC_BASE + 0x30))
#define GPIOD_MODER     (*(volatile unsigned int *)(GPIOD_BASE + 0x00))
#define GPIOD_ODR       (*(volatile unsigned int *)(GPIOD_BASE + 0x14))

/* Simple delay function */
void delay(void)
{
    for(int i=0;i<500000;i++);
}

int main(void)
{
    /* 1. Enable clock for GPIOD */
    RCC_AHB1ENR |= (1 << 3);

    /* 2. Configure PD14 as output */
    GPIOD_MODER &= ~(3 << (13 * 2));   // Clear mode bits
    GPIOD_MODER |=  (1 << (13 * 2));   // Set as output

    while(1)
    {
        /* 3. Turn LED ON */
        GPIOD_ODR |= (1 << 13);

        delay();

        /* 4. Turn LED OFF */
        GPIOD_ODR &= ~(1 << 13);

        delay();
    }
}
