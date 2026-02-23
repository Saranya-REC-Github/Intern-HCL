#include<stdio.h>
struct customer{
    int id;
    char cusname[20];
};
struct items{
    char itname[20];
    float price;
    int quantity;
};
struct orderdetails{
    int id;
    struct customer cuinfo;
    struct items itinfo;
};
int main(){
    struct orderdetails od1={25,{56,"Rocky"},{ "chapatti",15.0009,1}};
    printf("order ID: %d\n", od1.id);
    printf("customer ID: %d\n", od1.cuinfo.id);
    printf("cusname: %s\n", od1.cuinfo.cusname);
    printf("itemname: %s\n", od1.itinfo.itname);
    printf("item price: %.2f\n",od1.itinfo.price);
    printf("item quantity: %d\n",od1.itinfo.quantity);

    return 0;
}

