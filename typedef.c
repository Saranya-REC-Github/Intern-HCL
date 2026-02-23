//Use typedef or using to create an alias for a structure and demonstrate usage.
#include<stdio.h>
typedef struct student{
    char name[10];
    int roll;
    float marks;
}stu;
int main(){
    stu s1;
    fgets(s1.name,sizeof(s1.name),stdin);
    s1.roll=186;
    s1.marks=99.9;
    printf("Name:%s",s1.name);
    printf("roll:%d\n",s1.roll);
    printf("marks:%.2f\n ",s1.marks);
    return 0;
}
