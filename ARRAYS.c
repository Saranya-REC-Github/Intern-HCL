//Compute the average of an array using pointer arithmetic (no indexing).
#include <stdio.h>

int main() {
    int a[] = {11, 22, 33, 44, 55};
    int n = 5;
    int sum = 0;
    int *p = a;
    for (int i = 0; i < n; i++) {
        sum += *p;
        p++;
    }

    printf("Average = %.2f", (float)sum / n);
    return 0;
}
