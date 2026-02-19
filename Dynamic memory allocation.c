//Write a program to merge two sorted arrays into a single sorted output.
#include <stdio.h>
int main() {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    int c[6];
    int i = 0, j = 0, k = 0;
    while (i < 3 && j < 3) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < 3)
        c[k++] = a[i++];
    while (j < 3)
        c[k++] = b[j++];
    printf("Merged array: ");
    for (i = 0; i < 6; i++)
        printf("%d ", c[i]);
    return 0;
}
