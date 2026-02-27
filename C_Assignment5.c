//Two Sum | HackerRank
#include <stdio.h>
#include <stdlib.h>
int* findTaskPairForSlot(int taskDurations_count, int* taskDurations, int slotLength, int* result_count) {
    int* result = (int*)malloc(2 * sizeof(int));
    *result_count = 2;
    for(int i = 0; i < taskDurations_count; i++) {
        for(int j = i + 1; j < taskDurations_count; j++) {
            if(taskDurations[i] + taskDurations[j] == slotLength) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    result[0] = -1;
    result[1] = -1;
    return result;
}
int main() {
    int n;
    scanf("%d", &n);
    int* taskDurations = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &taskDurations[i]);
    }
    int slotLength;
    scanf("%d", &slotLength);
    int result_count;
    int* result = findTaskPairForSlot(n, taskDurations, slotLength, &result_count);
    printf("[%d, %d]\n", result[0], result[1]);
    free(taskDurations);
    free(result);
    return 0;
}
