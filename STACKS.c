//Use a stack to check balanced parentheses/brackets in an expression.
#include <stdio.h>
#include <string.h>
#define SIZE 100
int isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}
int isBalanced(char str[]) {
    char stack[SIZE];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isOpening(str[i])) {
            stack[++top] = str[i];
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {

            if (top == -1)
                return 0;
            char popped = stack[top--];
            if (!isMatching(popped, str[i]))
                return 0;
        }
    }

    return (top == -1);
}
int main() {
    char str[SIZE];
    printf("Enter a bracket expression: ");
    scanf("%s", str);
    if (isBalanced(str))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
