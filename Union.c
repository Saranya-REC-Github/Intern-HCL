//Create a union Data that can store either an integer, float, or string. Demonstrate how memory usage differs from a structure.
#include<stdio.h>
union data{
    int i;
    float f;
    char str[20];
};
struct datastruct{
    int i;
    float f;
    char str[20];
};
int main(){
    union data u;
    struct datastruct s;
    u.i=10;
    printf("enter int of union: %d\n",u.i);
    u.f=22.79;
    printf("enter float of union: %.2f\n",u.f);
    fgets(u.str,sizeof(u.str),stdin);
    printf("enter string of union: %s\n",u.str);

    printf("memory of union data: %lu bytes\n",sizeof(u));
    printf("memory of struct  datastruct: %lu bytes\n",sizeof(s));
    return 0;
}
