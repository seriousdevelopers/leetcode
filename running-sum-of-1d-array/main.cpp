#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int* returnedArray = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int total = 0;
    for(int i = 0; i < numsSize; i++) {
        total += nums[i];
        returnedArray[i] = total;
    }
    return returnedArray;
}

void doTest(int* nums, int numsSize) {
    int returnSize;
    int* returnedArray = runningSum(nums, numsSize, &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%d:(%d)\n", i, returnedArray[i]);
    }
    free(returnedArray);
}

int main() {
    int* p;
    int t1[4] = {1, 1, 1, 1};
    p = t1;
    doTest(t1, 4);

    int t2[4] = {1, 2, 3, 4};
    p = t2;
    doTest(t2, 4);

    int t3[5] = {1, 1, 1, 1, 1};
    p = t3;
    doTest(t3, 5);

    int t4[5] = {3, 1, 2, 10, 1};
    p = t4;
    doTest(t4, 5);

    return 0;
}