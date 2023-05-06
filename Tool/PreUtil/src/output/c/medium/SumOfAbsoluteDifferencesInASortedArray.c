/**https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/ */
//You are given an integer array nums sorted in non-decreasing order.
//Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.
//In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize){
    int* arr = malloc(numsSize * sizeof(int));
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    int leftSum = 0;
    for(int i = 0; i < numsSize; i++){
        arr[i] = (nums[i] * i - leftSum) + (sum - leftSum - nums[i] * (numsSize - i - 1));
        leftSum += nums[i];
    }
    *returnSize = numsSize;
    return arr;

}

    