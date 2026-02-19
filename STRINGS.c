//Write a function that returns the index of the first occurrence of a substring (naïve).
#include <stdio.h>
#include <string.h>
int findSubstring(char text[], char pat[]) {
    int n = strlen(text);
    int m = strlen(pat);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pat[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}
int main() {
    char text[] = "computer";
    char pat[] = "put";
    int index = findSubstring(text, pat);
    if (index != -1)
        printf("Substring found at index %d", index);
    else
        printf("Substring not found");
    return 0;
}

