#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a / b;
}
int main() {
    int choice, a, b, result;
    int (*operations[4])(int, int) = {add, sub, mul, divide};
    while (1) {
        printf("\n--- Calculator Menu ---\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 5)
            break;
        if (choice < 1 || choice > 4) {
            printf("Invalid choice!\n");
            continue;
        }
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        result = operations[choice - 1](a, b);
        printf("Result = %d\n", result);
    }
    return 0;
}
