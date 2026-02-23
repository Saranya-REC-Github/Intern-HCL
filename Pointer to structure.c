//Use a pointer to a struct Student to update marks and print updated details. Demonstrate why passing by pointer is efficient compared to passing by value.
#include <stdio.h>
struct student{
    int roll;
    char name[50];
    float marks;
};
void updatemarks(struct student *s,float newmarks){
    s->marks=newmarks;
}
void printstudent(struct student *s){
    printf("student details:\n");
    printf("Roll No : %d\n", s->roll);
    printf("Name    : %s\n", s->name);
    printf("Marks   : %.2f\n", s->marks);
}
int main(){
    struct student s1={155,"priya",89.70};
    printf("before update:\n");
    printstudent(&s1);
    updatemarks(&s1,98.76);
    printf("after update:\n");
    printstudent(&s1);
    return 0;
}
