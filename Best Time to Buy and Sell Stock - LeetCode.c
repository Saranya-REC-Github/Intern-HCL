//Best Time to Buy and Sell Stock - LeetCode
#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int i, minprice, maxprofit;

    minprice = INT_MAX;
    maxprofit = 0;

    for(i = 0; i < pricesSize; i++) {
        if(prices[i] < minprice) {
            minprice = prices[i];
        }
        else if(prices[i] - minprice > maxprofit) {
            maxprofit = prices[i] - minprice;
        }
    }

    return maxprofit;
}

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]);

    int result = maxProfit(prices, size);

    printf("Maximum Profit: %d\n", result);

    return 0;
}
