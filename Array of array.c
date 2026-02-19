//Create and use a function pointer to select different arithmetic operations at runtime.
#include <stdio.h>
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int division(int a, int b) {
if (b == 0) {
        printf("Division by zero is not allowed\n");
        return 0;
    }
return a / b; }
int main() {
    int choice, x = 10, y = 5;
    int (*fp)(int, int);
    printf("1.Add  2.Sub  3.Mul 4.Divide\n");
    scanf("%d", &choice);
    if (choice == 1) fp = add;
    else if (choice == 2) fp = sub;
    else if(choice==3)fp=mul;
    else fp = divide;
    printf("Result = %d", fp(x, y));
    return 0;
}

