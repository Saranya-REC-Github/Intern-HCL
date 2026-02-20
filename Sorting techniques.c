//Program that sorts numbers using the QuickSort method.
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    while(1){
        while(i<=high && arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if (i>=j)
            break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high){
        int s=partition(arr,low,high);
        quicksort(arr,low,s-1);
        quicksort(arr,s+1,high);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    quicksort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
