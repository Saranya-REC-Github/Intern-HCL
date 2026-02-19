//Check if a number is prime; then optimize by checking up to sqrt(n)
#include <stdio.h>
#include <math.h>

int main() {
    int n, flag = 1;
    scanf("%d", &n);

    if(n <= 1) {
        printf("Not Prime");
        return 0;
    }

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("Prime");
    else
        printf("Not Prime");

    return 0;
}

