//Implement a calculator using an array of function pointers for operations (+, -, *, /). Allow user to select operation at runtime.
#include<stdio.h>
int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int divide(int a,int b){
    if (b == 0) {
        printf("Division by zero is not allowed\n");
        return 0;
    }
    return a/b;
}
int main(){
    int a,b,choice,res;
    int (*ptr[])(int,int)={add,sub,mul,divide};
    printf("enter two numbers: ");
    scanf("%d %d",&a,&b);
    printf("\nSelect operation:\n");
    printf("0. Add (+)\n");
    printf("1. Sub (-)\n");
    printf("2. Mul (*)\n");
    printf("3. Divide (/)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 0:
        case 1:
        case 2:
        case 3:
            res=ptr[choice](a,b);
            printf("Result=%d",res);
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}
