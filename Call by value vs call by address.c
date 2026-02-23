//Write a custom dynamic array (vector) API supporting push(),pop(),resize()
#include<stdio.h>
#include<stdlib.h>
struct vector{
    int *arr;
    int size;
    int capacity;
};
void init(struct vector *v){
    v->capacity = 2;
    v->size = 0;
    v->arr =(int *)malloc(v->capacity*sizeof(int));
}
void push(struct vector *v,int value){
    if(v->size >= v->capacity){
        v->capacity=v->capacity*2;
        v->arr=(int *)realloc(v->arr,v->capacity*sizeof(int));
        printf("Array is resized to %d\n",v->capacity);
    }
    v->arr[v->size]=value;
    v->size++;
}
void pop(struct vector *v){
    if(v->size==0){
        printf("Array is empty");
        return;
    }
    v->size--;
}
void resize(struct vector *v,int newcapci){
    if(newcapci < v->size){
        printf("New capcity is too small\n");
        return;
    }
    v->capacity=newcapci;
    v->arr=(int *)realloc(v->arr,newcapci * sizeof(int));
}
void display(struct vector *v){
    for(int i=0;i< v->size;i++){
        printf("%d ",v->arr[i]);
    }
    printf("\n");
}
int main(){
    struct vector v;
    init(&v);
    push(&v,50);
    push(&v,100);
    push(&v,150);
    display(&v);
    pop(&v);
    display(&v);
    resize(&v,15);
    printf("Capacity changed to 15\n");
    free(v.arr);
    return 0;
}
