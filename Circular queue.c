//Implement a queue using two stacks; analyze amortized complexity.
#include<stdio.h>
#define MAX 100
struct stack{
    int arr[MAX];
    int top;
};
void initstack(struct stack *s){
    s->top=-1;
}
void push(struct stack *s,int x ){
    s->arr[++s->top]=x;
}
int pop(struct stack *s){
    return s->arr[s->top--];
}
int isEmpty(struct stack *s){
    return s->top==-1;
}
void enqueue(struct stack *s1,int x){
    push(s1,x);
    printf("Enqueued: %d\n", x);
}
int dequeue(struct stack *s1, struct stack *s2){
    if(isEmpty(s2)){
        while(!isEmpty(s1)){
            push(s2,pop(s1));
        }
    }
    if (isEmpty(s2)) {
        printf("Queue is empty\n");
        return -1;
    }

    return pop(s2);
}
int main(){
    struct stack s1,s2;
    initstack(&s1);
    initstack(&s2);
    enqueue(&s1, 10);
    enqueue(&s1, 20);
    enqueue(&s1, 30);
    printf("Dequeued: %d\n", dequeue(&s1, &s2));
    printf("Dequeued: %d\n", dequeue(&s1, &s2));
    printf("Dequeued: %d\n", dequeue(&s1, &s2));
    return 0;
}

