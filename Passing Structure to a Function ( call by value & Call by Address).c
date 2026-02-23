//Define a struct Product with price and discount. Write two functions:
//One that calculates discounted price (call by value).
//Another that updates the price in the original structure (call by address).
#include<stdio.h>
struct product{
    float price;
    float discount;
};
float calculateDiscountedPrice( struct product p){
    float discountedPrice;
    discountedPrice= p.price -(p.price * p.discount / 100);
    return  discountedPrice;
}
void applyDiscount(struct product *p){
    p->price=p->price - (p->price * p->discount/100);
}
int main(){
    struct product item;
    printf("Enter product price: ");
    scanf("%f", &item.price);
    printf("Enter discount percentage: ");
    scanf("%f", &item.discount);
    float finalPrice = calculateDiscountedPrice(item);
    printf("\nDiscounted price (Call by Value): %.2f\n", finalPrice);
    printf("Original price after call by value: %.2f\n", item.price);
    applyDiscount(&item);
    printf("\nPrice after applying discount (Call by Address): %.2f\n", item.price);

    return 0;
}
