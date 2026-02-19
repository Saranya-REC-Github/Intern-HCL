//Implement strcpy safely (bounded copy) and discuss buffer overflow risks.
#include <stdio.h>
void safeCopy(char dest[], char src[], int size) {
    int i;
    for (i = 0; i < size - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
int main() {
    char src[] = "GreatSiri";
    char dest[6];
    safeCopy(dest, src, sizeof(dest));
    printf("Copied string: %s", dest);
    return 0;
}
