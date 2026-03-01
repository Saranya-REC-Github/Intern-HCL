//Count Number Pairs | HackerRank
#include <stdio.h>
int countAffordablePairs(int prices_count, int* prices, int budget) {
    int n = prices_count;
    int c = 0;
    if(n > 0) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(prices[i] + prices[j] <= budget) {
                    c++;
                }
            }
        }
    }
    return c;
}
int main() {
    int n, budget;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int prices[n];   // Array of size n
    printf("Enter prices:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    printf("Enter budget: ");
    scanf("%d", &budget);
    int result = countAffordablePairs(n, prices, budget);
    printf("Number of affordable pairs: %d\n", result);
    return 0;
}
