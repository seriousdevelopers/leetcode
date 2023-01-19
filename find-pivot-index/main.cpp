#include <stdlib.h>
#include <stdio.h>

int pivotIndex(int* nums, int numsSize) {    
    int pivotIndex = -1;    
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }
    int sumOfLeft = 0;
    for (int i = 0; i < numsSize; i++) {        
        int sumOfRight = totalSum - sumOfLeft - nums[i];
        if (sumOfLeft == sumOfRight) {            
            pivotIndex = i;
            break;
        }
        sumOfLeft += nums[i];
    }
    return pivotIndex;
}

void doTest(int* nums, int numsSize) {
    int result = pivotIndex(nums, numsSize);
    printf("result(%d)\n", result);
}

int main() {
    int* p;

    do {
        int N = 6;
        int t1[N] = {1, 7, 3, 6, 5, 6};
        p = t1;
        doTest(t1, N);
    } while(0);

    do {
        int N = 3;
        int t1[N] = {1, 2, 3};
        p = t1;
        doTest(t1, N);
    } while(0);

    do {
        int N = 3;
        int t1[N] = {2, 1, -1};
        p = t1;
        doTest(t1, N);
    } while(0);

    return 0;
}