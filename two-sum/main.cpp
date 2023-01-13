#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int* nums;
    const int numsSize = 4;
    nums = (int*)malloc(sizeof(int) * numsSize);
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;
    int returnSize;
    int target = 9;
    int* returnedArray = twoSum(nums, numsSize, target, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d\n", returnedArray[i]);
    }
    free(returnedArray);
    free(nums);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* returnedArray = (int*)malloc(sizeof(int) * 2);
    bool flagFound = false;
    for(int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                returnedArray[0] = i;
                returnedArray[1] = j;
                flagFound = true;
                break;
            }
        }
        if(flagFound) {
            break;
        }
    }
    *returnSize = 2;
    return returnedArray;
}