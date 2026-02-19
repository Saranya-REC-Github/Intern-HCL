//Reverse an integer (e.g.,12345 -> 54321) and discuss overflow for 32-bit ints.
#include <stdio.h>

int main() {
    int n, rev = 0;
    scanf("%d", &n);

    while(n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    printf("Reversed number = %d", rev);

    return 0;
}
