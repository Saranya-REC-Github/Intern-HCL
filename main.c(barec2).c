#include <stdint.h>

/* Base addresses */
#define RCC_BASE   0x40023800
#define GPIOD_BASE 0x40020C00

/* Register definitions */
#define RCC_AHB1ENR (*(volatile unsigned int *)(RCC_BASE + 0x30))
#define GPIOD_MODER (*(volatile unsigned int *)(GPIOD_BASE + 0x00))
#define GPIOD_ODR   (*(volatile unsigned int *)(GPIOD_BASE + 0x14))

int main(void)
{
    /* Enable clock for GPIOD */
    RCC_AHB1ENR |= (1<<3);

    /* Configure PD12 as output */
    GPIOD_MODER &= ~(3<<(12*2));
    GPIOD_MODER |=  (1<<(12*2));

    /* Switch ON Green LED */
    GPIOD_ODR |= (1<<12);

    while(1)
    {
        // LED stays ON indicating successful communication
    }
}
