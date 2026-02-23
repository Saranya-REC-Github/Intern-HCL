//Count word frequencies in a paragraph using a fixed-size array of unique words.
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 50
#define WORD_LEN 20
int main(){
    char paragraph[200];
    char words[MAX_WORDS][WORD_LEN];
    int freq[MAX_WORDS] = {0};
    int count = 0;
    printf("Enter a paragraph:\n");
    fgets(paragraph,sizeof(paragraph),stdin);
    char *token = strtok(paragraph, " ,.!?\n");
    while (token != NULL)
    {
        int found = 0;
// Checking if word already exists
        for (int i = 0; i < count; i++)
        {
            if (strcmp(words[i], token) == 0)
            {
                freq[i]++;
                found = 1;
                break;
            }
        }
// If it is new word
        if (!found)
        {
            strcpy(words[count], token);
            freq[count] = 1;
            count++;
        }
        token = strtok(NULL, " ,.!?\n");
    }
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s : %d\n", words[i], freq[i]);
    }
    return 0;
}
