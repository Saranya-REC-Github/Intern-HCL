//Write a function that swaps two pointers using a pointer-to-pointer. Demonstrate with two dynamically allocated strings.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapPointers(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    char *str1 = (char *)malloc(10 * sizeof(char));
    char *str2 = (char *)malloc(10 * sizeof(char));
    strcpy(str1, "Hello");
    strcpy(str2, "cprogramming");

    printf("Before swap:\n");
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    swapPointers(&str1, &str2);
    printf("\nAfter swap:\n");
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    free(str1);
    free(str2);

    return 0;
}
