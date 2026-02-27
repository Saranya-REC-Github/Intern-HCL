//Count Elements Greater Than Previous Average | HackerRank
#include <stdio.h>
#include <stdlib.h>
int countResponseTimeRegressions(int responseTimes_count, int* responseTimes)
{
    if (responseTimes_count <= 1)
        return 0;
    long long sum = responseTimes[0];  // To store sum of previous elements
    int count = 0;
    for (int i = 1; i < responseTimes_count; i++)
    {
        double avg = (double)sum / i;  // Average of previous elements
        if (responseTimes[i] > avg)
            count++;
        sum += responseTimes[i];
    }
    return count;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0");
        return 0;
    }
    int* responseTimes = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &responseTimes[i]);
    }
    int result = countResponseTimeRegressions(n, responseTimes);
    printf("%d", result);
    free(responseTimes);
    return 0;
}
