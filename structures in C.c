//Create a struct Student with fields for roll number, name, and marks. Write a program to input details for 5 students and display the topper’s details.
#include <stdio.h>

struct stu {
    int roll;
    char name[10];
    float marks;
};

int main() {
    struct stu s[5];
    int i, topperindex = 0;

    for (i = 0; i < 5; i++) {
        printf("Enter details of student %d:\n", i + 1);

        printf("roll number:");
        scanf("%d", &s[i].roll);

        printf("name:");
        scanf(" %[^\n]", s[i].name);

        printf("marks:");
        scanf("%f", &s[i].marks);
    }

    for (i = 1; i < 5; i++) {
        if (s[i].marks > s[topperindex].marks) {
            topperindex = i;
        }
    }

    printf("\n--- Topper Details ---\n");
    printf("Roll Number: %d\n", s[topperindex].roll);
    printf("Name: %s\n", s[topperindex].name);
    printf("Marks: %.2f\n", s[topperindex].marks);

    return 0;
}
