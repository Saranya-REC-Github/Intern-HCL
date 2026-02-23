//Maintain an array of struct Employee for 10 employees. Calculate total salary payout and find the employee with the highest salary.
#include <stdio.h>
struct Employee {
    int id;
    char name[30];
    float salary;
};
int main() {
    struct Employee e[10];
    float totalSalary = 0;
    int i, maxIndex = 0;
    for (i = 0; i < 10; i++) {
        printf("\nEnter details of Employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &e[i].id);
        printf("Name: ");
        scanf("%s", e[i].name);
        printf("Salary: ");
        scanf("%f", &e[i].salary);
        totalSalary += e[i].salary;
        if (e[i].salary > e[maxIndex].salary) {
            maxIndex = i;
        }
    }
    printf("\nTotal Salary Payout = %.2f\n", totalSalary);
    printf("\nEmployee with Highest Salary:\n");
    printf("ID: %d\n", e[maxIndex].id);
    printf("Name: %s\n", e[maxIndex].name);
    printf("Salary: %.2f\n", e[maxIndex].salary);
    return 0;
}

