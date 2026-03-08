//Given a string of brackets like "({[]})", use a list as a stack to determine if the string is balanced.
#include <stdio.h>
#include <string.h>
#define SIZE 100
int main() {
    char str[SIZE];
    char stack[SIZE];
    int top = -1;
    printf("Enter a bracket string: ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {
                printf("Not Balanced\n");
                return 0;
            }
            char popped = stack[top--];
            if ((str[i] == ')' && popped != '(') ||
                (str[i] == '}' && popped != '{') ||
                (str[i] == ']' && popped != '[')) {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    if (top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
