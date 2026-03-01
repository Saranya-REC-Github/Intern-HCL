//Search Insert Position - LeetCode
#include <stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(nums[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}
int main() {
    int nums[] = {1, 3, 5, 6};
    int size = 4;
    int target = 5;
    int position = searchInsert(nums, size, target);
    printf("Target position: %d\n", position);
    return 0;
}
