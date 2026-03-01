//Remove Element - LeetCode
#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
int main() {
    int nums[] = {3, 2, 2, 3};
    int size = 4;
    int val = 3;
    int newSize = removeElement(nums, size, val);
    printf("New length: %d\n", newSize);
    printf("Array after removing %d:\n", val);
    for(int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
