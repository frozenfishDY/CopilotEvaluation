/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 3);
    int* queue = (int*)malloc(sizeof(int) * numsSize);
    int head = 0, tail = 0;
    for(int i = 0; i < numsSize; i++){
        while(head < tail && nums[queue[tail - 1]] < nums[i]) tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k) head++;
        if(i >= k - 1) result[i - k + 1] = nums[queue[head]];
    }
    *returnSize = numsSize - k + 1;
    return result;

}

    