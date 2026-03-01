//Length of Last Word - LeetCode
#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char* s) {
    int n = strlen(s);
    int c = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ' ') {
            if(c > 0) {
                return c;
            }
        }
        else {
            c++;
        }
    }
    return c;
}
int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if(str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    int result = lengthOfLastWord(str);
    printf("Length of last word: %d\n", result);
    return 0;
}
