//Given a temperature in Celsius, convert and print in Fahrenheit with one decimal.
#include <stdio.h>

int main() {
    float c, f;
    scanf("%f", &c);

    f = (c * 9/5) + 32;

    printf("Fahrenheit = %.2f\n", f);
    return 0;
}

