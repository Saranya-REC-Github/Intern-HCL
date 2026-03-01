//Longest Common Prefix - LeetCode
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    int n = strsSize;
    if(n == 0){
        char* empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }
    char* prefix = malloc(200);
    strcpy(prefix, strs[0]);
    for(int i = 1; i < n; i++){
        while(strncmp(prefix, strs[i], strlen(prefix)) != 0){
            prefix[strlen(prefix) - 1] = '\0';

            if(strlen(prefix) == 0){
                return prefix;
            }
        }
    }
    return prefix;
}
int main() {
    char* arr[] = {"flower", "flow", "flight"};
    int size = 3;
    char* result = longestCommonPrefix(arr, size);
    printf("Longest Common Prefix: %s\n", result);
    free(result);
    return 0;
}
