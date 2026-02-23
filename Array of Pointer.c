//Create an array of char* to store names of cities entered by the user. Implement functions to sort them alphabetically and free allocated memory.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sortCities(char *cities[], int n);
void freeMemory(char *cities[], int n);
void sortCities(char *cities[], int n)
{
    char *temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcasecmp(cities[i], cities[j]) > 0)
            {
                temp = cities[i];
                cities[i] = cities[j];
                cities[j] = temp;
            }
        }
    }
}
void freeMemory(char *cities[], int n)
{
    for (int i = 0; i < n; i++)
    {
        free(cities[i]);
    }
}
int main()
{
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    getchar();
    char *cities[n];
    for (int i = 0; i < n; i++)
    {
        cities[i] = (char *)malloc(50 * sizeof(char));
        printf("Enter city %d: ", i + 1);
        fgets(cities[i], 50, stdin);
        cities[i][strcspn(cities[i], "\n")] = '\0';
    }
    sortCities(cities, n);
    printf("\nCities in Alphabetical Order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", cities[i]);
    }
    freeMemory(cities, n);
    return 0;
}
