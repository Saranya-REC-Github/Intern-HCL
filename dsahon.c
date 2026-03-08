//Given an array containing only 0, 1, and 2, sort it without using any built-in sort function.
#include <stdio.h>
int main() {
    int arr[] = {0, 2, 1, 2, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }
    int index = 0;

    while (count0--)
        arr[index++] = 0;

    while (count1--)
        arr[index++] = 1;

    while (count2--)
        arr[index++] = 2;
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
