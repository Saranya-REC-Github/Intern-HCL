//Validate Properly Nested Brackets | HackerRank
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool areBracketsProperlyMatched(char* code_snippet) {
    char stack[1000];
    int top = -1;
    for(int i = 0; code_snippet[i] != '\0'; i++) {
        char ch = code_snippet[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(top == -1) {
                return false;
            }
            char last = stack[top--];
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                return false;
            }
        }
    }
    return (top == -1);
}
int main() {
    char code_snippet[1000];
    fgets(code_snippet, sizeof(code_snippet), stdin);
    if (areBracketsProperlyMatched(code_snippet))
        printf("1");
    else
        printf("0");
    return 0;
}
