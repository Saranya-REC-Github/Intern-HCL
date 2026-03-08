//Given tokens of an RPN expression (e.g., ["2","1","+","3","*"]), use a list as a stack to compute the result.#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#define SIZE 100
int main() {
    char tokens[SIZE][10];
    int stack[SIZE];
    int top = -1, n;
    printf("Enter number of tokens: ");
    scanf("%d", &n);
    printf("Enter RPN tokens:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", tokens[i]);
    for (int i = 0; i < n; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            stack[++top] = atoi(tokens[i]);
        }
        else {
            int b = stack[top--];
            int a = stack[top--];
            int result;
            if (tokens[i][0] == '+')
                result = a + b;
            else if (tokens[i][0] == '-')
                result = a - b;
            else if (tokens[i][0] == '*')
                result = a * b;
            else if (tokens[i][0] == '/')
                result = a / b;
            stack[++top] = result;
        }
    }
    printf("Result = %d\n", stack[top]);
    return 0;
}


