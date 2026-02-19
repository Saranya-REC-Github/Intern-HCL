//Write a program in C to check Armstrong and Perfect numbers using the function.
#include <stdio.h>
#include <math.h>
int isArmstrong(int num) {
    int real = num, digit, sum = 0, count = 0;
    int temp = num;
    while (temp > 0) {
        count++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0) {
        digit = temp % 10;
        sum += pow(digit, count);
        temp /= 10;
    }

    return (sum == real);
}
int isPerfect(int num) {
    int sum = 0;

    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0)
            sum += i;
    }

    return (sum == num);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (isArmstrong(n))
        printf("%d is an Armstrong number\n", n);
    else
        printf("%d is NOT an Armstrong number\n", n);
    if (isPerfect(n))
        printf("%d is a Perfect number\n", n);
    else
        printf("%d is NOT a Perfect number\n", n);
     return 0;
}
