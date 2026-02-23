//Define an enum Status with values PENDING, SHIPPED, DELIVERED. Write a program to update and display order status using the enum.
#include<stdio.h>
enum status_values{pending=0,shipped=1,delivered=2};
int main(){
    enum status_values orderstatus;
    printf("Enter Order Status: ");
    scanf("%d", &orderstatus);
    switch(orderstatus){
        case pending:
            printf("orderstatus=pending\n");
            break;
        case shipped:
            printf("orderstatus=shipped\n");
            break;
        case delivered:
            printf("orderstatus=delivered\n");
            break;
        default:
            printf("Invalid Order Status\n");
    }
    return 0;
}
