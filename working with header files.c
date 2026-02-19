//Read a string (with spaces) safely and print its length without using strlen.
#include <stdio.h>

int main() {
    char str[100];
    int length = 0;
    fgets(str, sizeof(str), stdin);
    while(str[length] != '\0' && str[length] != '\n') {
        length++;
    }
    printf("Length = %d", length);

    return 0;
}
