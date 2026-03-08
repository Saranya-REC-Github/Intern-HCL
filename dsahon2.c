//Given an array and an integer k, rotate the array to the right by k steps efficiently.
#include <stdio.h>
int main() {
    int a[10],i,j,k, n;
    int temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter number of rotations: ");
    scanf("%d", &k);
    k=k%n;
    for(i=0;i<k;i++){
        temp=a[n-1];
        for(j=n-1;j>0;j--){
            a[j]=a[j-1];
        }
        a[0]=temp;
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
