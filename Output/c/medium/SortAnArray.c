/**https://leetcode.com/problems/sort-an-array/ */
//Given an array of integers nums, sort the array in ascending order and return it.
//You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        result[i] = nums[i];
    }
    quickSort(result, 0, numsSize - 1);
    return result;

}

    