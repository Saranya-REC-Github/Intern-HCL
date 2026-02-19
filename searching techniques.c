//Program to find the position of a target value within an array using linear search.
#include <stdio.h>

int main() {
    int a[100], n, key, i, pos = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            pos = i + 1;
            break;
        }
    }
    if (pos != -1)
        printf("Element found at position %d\n", pos);
    else
        printf("Element not found\n");

    return 0;
}

