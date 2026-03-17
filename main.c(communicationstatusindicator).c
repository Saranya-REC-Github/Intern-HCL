#include <stdint.h>

#define RCC_BASE   0x40023800
#define GPIOD_BASE 0x40020C00

#define RCC_AHB1ENR (*(volatile unsigned int*)(RCC_BASE+0x30))
#define GPIOD_MODER (*(volatile unsigned int*)(GPIOD_BASE+0x00))
#define GPIOD_ODR   (*(volatile unsigned int*)(GPIOD_BASE+0x14))

void delay(){
    for(int i=0;i<500000;i++);
}

int main()
{
    RCC_AHB1ENR |= (1<<3);          // Enable GPIOD clock

    /* Set PD12, PD13, PD14 as output */
    GPIOD_MODER |= (1<<(12*2));
    GPIOD_MODER |= (1<<(13*2));
    GPIOD_MODER |= (1<<(14*2));

    /* Green LED ON – successful communication */
    GPIOD_ODR |= (1<<12);

    while(1)
    {
        /* Orange LED blinking – communication activity */
        GPIOD_ODR ^= (1<<13);
        delay();

        /* Red LED blinking – communication fault indication */
        GPIOD_ODR ^= (1<<14);
        delay();
    }
}
