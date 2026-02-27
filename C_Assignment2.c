//Find the Smallest Missing Positive Integer | HackerRank
#include <stdio.h>
#include <stdlib.h>
int findSmallestMissingPositive(int orderNumbers_count, int* orderNumbers)
{
    int n = orderNumbers_count;
    for (int i = 0; i < n; i++)
    {
        while (orderNumbers[i] > 0 &&
               orderNumbers[i] <= n &&
               orderNumbers[orderNumbers[i] - 1] != orderNumbers[i])
        {
            int temp = orderNumbers[i];
            orderNumbers[i] = orderNumbers[temp - 1];
            orderNumbers[temp - 1] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (orderNumbers[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("1");
        return 0;
    }
    int* orderNumbers = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &orderNumbers[i]);
    }
    int result = findSmallestMissingPositive(n, orderNumbers);
    printf("%d", result);
    free(orderNumbers);
    return 0;
}
