//Climbing Stairs - LeetCode
#include <stdio.h>
int climbStairs(int n) {
    if(n <= 3){
        return n;
    }
    int a = 2;
    int b = 3;
    int c;
    for(int i = 4; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main() {
    int n;
    printf("Enter number of stairs: ");
    scanf("%d", &n);
    int result = climbStairs(n);
    printf("Number of ways to climb %d stairs: %d\n", n, result);
    return 0;
}
