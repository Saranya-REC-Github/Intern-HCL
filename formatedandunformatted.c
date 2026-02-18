//Read a character and report whether it is a vowel, consonant, digit, or special symbol.
#include <stdio.h>
#include <ctype.h>
int main() {
    char ch;
    scanf("%c", &ch);
    if (ch >= '0' && ch <= '9') {
        printf("Digit");
    }
    else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u') {
            printf("Vowel");
        } else {
            printf("Consonant");
        }
    }
    else {
        printf("Special Symbol");
    }

    return 0;
}
