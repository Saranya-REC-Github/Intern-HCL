//Implement a queue using a circular array (ring buffer); demonstrate wrap-around.
#include<stdio.h>
#define size 5
int queue[size];
int front=-1,rear=-1;
void enqueue(int value){
    if((rear+1)%size==front){
        printf("Queue is empty\n");
        return;
    }
    if(front==-1)
        front=0;
    rear=(rear+1)%size;
    queue[rear]=value;
    printf("Enqueued value is:%d\n",value);
}
void dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued value is:%d\n",queue[front]);
    if(front==rear){
        front=rear=-1;
    }else{
        front=(front+1)%size;
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:  ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    enqueue(50);
    enqueue(60);   // wrap-around happens here
    display();
    return 0;
}
