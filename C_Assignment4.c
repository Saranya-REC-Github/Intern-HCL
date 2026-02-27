//Remove Elements Within K Distance | HackerRank
#include <stdio.h>
int debounceTimestamps(int timestamps_count, int* timestamps, int K) {
    int write = 0;
    for (int read = 1; read < timestamps_count; read++) {
        if (timestamps[read] - timestamps[write] >= K) {
            write++;
            timestamps[write] = timestamps[read];
        }
    }
    return write + 1;
}
int main() {
    int timestamps[] = {1, 2, 3, 8, 10};
    int K = 3;
    int n = 5;
    int newLength = debounceTimestamps(n, timestamps, K);
    printf("New length: %d\n", newLength);
    printf("Updated timestamps: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", timestamps[i]);
    }
    return 0;
}
