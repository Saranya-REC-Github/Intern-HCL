//Ways to Fill Slots with Single or Double Coverage | HackerRank
#include <stdio.h>
#include <stdlib.h>
char* countInstallationSequences(int n) {
    long long result;
    if (n == 0 || n == 1) {
        result = 1;
    }
    else {
        long long a = 1;
        long long b = 1;
        long long temp;
        for (int i = 2; i <= n; i++) {
            temp = a + b;
            a = b;
            b = temp;
        }
        result = b;
    }
    char* output = malloc(30 * sizeof(char));
    sprintf(output, "%lld", result);
    return output;
}
int main() {
    int n;
    printf("Enter number of slots: ");
    scanf("%d", &n);
    char* result = countInstallationSequences(n);
    printf("Number of ways: %s\n", result);
    free(result);   // Important: Free allocated memory
    return 0;
}
