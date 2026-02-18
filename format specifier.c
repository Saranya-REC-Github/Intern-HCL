//Swap two integers without using a temporary variable.
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("After swap: a = %d, b = %d", a, b);

    return 0;
}

