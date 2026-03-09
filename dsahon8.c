//Simulate a round-robin CPU scheduler using a circular queue.
#include <stdio.h>
int main() {
    int n, tq;
    int bt[10], rt[10];
    int time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // remaining time
    }
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    printf("\nProcess Execution Order:\n");
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                printf("P%d ", i + 1);
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }
    }
    printf("\nTotal Time = %d\n", time);
    return 0;
}
