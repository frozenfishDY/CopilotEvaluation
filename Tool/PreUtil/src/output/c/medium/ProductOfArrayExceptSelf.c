/**https://leetcode.com/problems/product-of-array-except-self/ */
//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//You must write an algorithm that runs in O(n) time and without using the division operation.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int* left = (int*)malloc(sizeof(int) * numsSize);
    int* right = (int*)malloc(sizeof(int) * numsSize);
    left[0] = 1;
    right[numsSize - 1] = 1;
    for(int i = 1; i < numsSize; i++){
        left[i] = left[i - 1] * nums[i - 1];
    }
    for(int i = numsSize - 2; i >= 0; i--){
        right[i] = right[i + 1] * nums[i + 1];
    }
    for(int i = 0; i < numsSize; i++){
        result[i] = left[i] * right[i];
    }
    *returnSize = numsSize;
    return result;

}

    