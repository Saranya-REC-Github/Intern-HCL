//Allocate memory dynamically for struct Item array based on user input size. Implement add and delete operations safely.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct item{
    int id;
    char name[10];
};
void additem(struct item *items,int *count,int capacity){
    if(*count>=capacity){
        printf("Item cannot be added as the array is full\n");
        return;
    }
    printf("Enter item ID: ");
    scanf("%d",&items[*count].id);
    printf("Enter item Name: ");
    scanf("%s",items[*count].name);
    (*count)++;
    printf("Item added successfully\n");
}
void delitem(struct item *items,int *count,int index){
    if(index<0 ||index>=*count){
        printf("Invalid index\n");
        return;
    }
    for(int i=index;i<*count-1;i++){
        items[i]=items[i+1];
    }
    (*count)--;
    printf("Item deleted successfully\n");

}
void displayitems(struct item *items,int count){
    if(count==0){
        printf("No items to display\n");
        return;
    }
    for(int i=0;i<count;i++){
        printf("item %d -> ID: %d,Name: %s\n",i,items[i].id,items[i].name);
    }
}
int main(){
    int size,choice,index;
    int count=0;
    printf("Enter no.of. items to allocate: ");
    scanf("%d",&size);
    struct item  *items=(struct item *)malloc(size * sizeof(struct item));
    if(items==NULL){
        printf("Memory allocation  failed\n");
        return 1;
    }
    do{
        printf("\n1. Add Item\n2. Delete Item\n3. Display Items\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                additem(items,&count,size);
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%d",&index);
                delitem(items,&count,index);
                break;
            case 3:
                displayitems(items,count);
                break;
            case 4:
                printf("Exit \n");
                break;
            case 5:
                printf("invalid choice\n");
        }
    }while(choice!=4);
    free(items);
    return 0;
}
