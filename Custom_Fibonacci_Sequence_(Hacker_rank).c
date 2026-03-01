//Custom Fibonacci Sequence | HackerRank
#include <stdio.h>
long getAutoSaveInterval(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    long a = 1, b = 2;
    for (int i = 2; i <= n; i++) {
        long c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if(n < 0) {
        printf("Invalid input! n must be non-negative.\n");
        return 0;
    }
    long result = getAutoSaveInterval(n);
    printf("F(%d) = %ld\n", n, result);
    return 0;
}
