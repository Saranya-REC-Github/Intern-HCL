int compareIntervals(const void* a, const void* b) {
    int* A = *(int**)a;
    int* B = *(int**)b;
    return A[0] - B[0];
}
int** mergeHighDefinitionIntervals(int intervals_rows, int intervals_columns, int** intervals,
                                   int* result_rows, int* result_columns) {
    if (intervals_rows == 0) {
        *result_rows = 0;
        *result_columns = 0;
        return NULL;
    }
    qsort(intervals, intervals_rows, sizeof(int*), compareIntervals);
    int** result = (int**)malloc(intervals_rows * sizeof(int*));
    int count = 0;
    result[count] = (int*)malloc(2 * sizeof(int));
    result[count][0] = intervals[0][0];
    result[count][1] = intervals[0][1];
    count++;
    for (int i = 1; i < intervals_rows; i++) {
        int start = intervals[i][0];
        int end   = intervals[i][1];

        if (start <= result[count - 1][1]) {
            if (end > result[count - 1][1]) {
                result[count - 1][1] = end;
            }
        } else {
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = start;
            result[count][1] = end;
            count++;
        }
    }
    *result_rows = count;
    *result_columns = 2;
    return result;
}
