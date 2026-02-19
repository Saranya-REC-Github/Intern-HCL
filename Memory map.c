//Remove all occurrences of a given character from a string in-place.
#include <stdio.h>

int main() {
    char str[100];
    char ch;
    int i, j = 0;

    printf("Enter a string: ");
    gets(str);
    printf("Enter character to remove: ");
    scanf("%c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';

    printf("Final string: %s\n", str);

    return 0;
}
