//Pass a 9x9 integer array to a function that checks if each row and column contains unique numbers from 1 to 9
#include<stdio.h>
int checkuniquenum(int grid[9][9]){
    int freq[10];
    for(int row=0;row<9;row++){
        for(int i=1;i<=9;i++)
            freq[i]=0;
        for(int col=0;col<9;col++){
            int num=grid[row][col];
            if(num<1 || num>9)
                return 0;
            if(freq[num]==1)
                return 0;
            freq[num]=1;
        }
    }
    for(int col=0;col<9;col++){
        for(int i=1;i<=9;i++)
            freq[i]=0;
        for(int row=0;row<9;row++){
            int num=grid[row][col];
            if(num<1 || num>9)
                return 0;
            if(freq[num]==1)
                return 0;
            freq[num]=1;
        }
    }
    return 1;
}
int main() {
    int grid[9][9] = {
        {1,2,3,4,5,6,7,8,9},
        {2,3,4,5,6,7,8,9,1},
        {3,4,5,6,7,8,9,1,2},
        {4,5,6,7,8,9,1,2,3},
        {5,6,7,8,9,1,2,3,4},
        {6,7,8,9,1,2,3,4,5},
        {7,8,9,1,2,3,4,5,6},
        {8,9,1,2,3,4,5,6,7},
        {9,1,2,3,4,5,6,7,8}
    };
    if (checkuniquenum(grid))
        printf("***Valid grid***\n");
    else
        printf("***Invalid grid***\n");
    return 0;
}
