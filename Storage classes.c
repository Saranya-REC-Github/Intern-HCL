//Check if a string is a palindrome (ignore case and non-alphanumeric).
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);

    int start = 0;
    int end = strlen(str) - 1;

    if(str[end] == '\n') end--;

    while(start < end) {
        if(tolower(str[start]) != tolower(str[end])) {
            printf("Not Palindrome");
            return 0;
        }
        start++;
        end--;
    }

    printf("Palindrome");
    return 0;
}
