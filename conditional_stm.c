//Compute the factorial of n using an iterative loop; handle n=0 correctly.
#include <stdio.h>

int main() {
    int n;
    long long fact = 1;

    scanf("%d", &n);

    if(n < 0) {
        printf("Factorial not defined");
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        fact *= i;
    }

    printf("Factorial = %lld", fact);

    return 0;
}
