#include <stdint.h>

/* Base addresses */
#define RCC_BASE   0x40023800
#define GPIOD_BASE 0x40020C00

/* Register definitions */
#define RCC_AHB1ENR (*(volatile unsigned int *)(RCC_BASE + 0x30))
#define GPIOD_MODER (*(volatile unsigned int *)(GPIOD_BASE + 0x00))
#define GPIOD_ODR   (*(volatile unsigned int *)(GPIOD_BASE + 0x14))

void delay()
{
    for(int i=0;i<500000;i++);
}

int main(void)
{
    /* Enable clock for GPIOD */
    RCC_AHB1ENR |= (1<<3);

    /* Configure PD14 as output */
    GPIOD_MODER &= ~(3<<(14*2));
    GPIOD_MODER |=  (1<<(14*2));

    while(1)
    {
        /* Red LED ON */
        GPIOD_ODR |= (1<<14);
        delay();

        /* Red LED OFF */
        GPIOD_ODR &= ~(1<<14);
        delay();
    }
}
