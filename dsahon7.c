//Given an array and a window size k, use a deque to find the maximum element in each sliding window
#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n], deque[n];
    int front = 0, rear = -1;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < k; i++) {
        while (rear >= front && a[deque[rear]] <= a[i])
            rear--;
        deque[++rear] = i;
    }
    for (int i = k; i < n; i++) {
        printf("%d ", a[deque[front]]);
        while (front <= rear && deque[front] <= i - k)
            front++;
        while (rear >= front && a[deque[rear]] <= a[i])
            rear--;
        deque[++rear] = i;
    }
    printf("%d", a[deque[front]]);
    return 0;
}

