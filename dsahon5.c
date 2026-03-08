//For a circular array A (the element after the last is the first), compute the Next Greater Element for each index using a stack.
#include <stdio.h>
int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int a[n], res[n], stack[n], top = -1;
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        res[i] = -1;   // default
    }
    for (int i = 0; i < 2 * n; i++) {
        int curr = a[i % n];
        while (top != -1 && a[stack[top]] < curr) {
            res[stack[top--]] = curr;
        }
        if (i < n)
            stack[++top] = i;
    }
    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);
    return 0;
}
