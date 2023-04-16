/**https://leetcode.com/problems/sum-of-even-numbers-after-queries/ */
//You are given an integer array nums and an array queries where queries[i] = [vali, indexi].
//For each query i, first, apply nums[indexi] = nums[indexi] + vali, then print the sum of the even values of nums.
//Return an integer array answer where answer[i] is the answer to the ith query.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * queriesSize);
    *returnSize = 0;
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] % 2 == 0){
            sum += nums[i];
        }
    }
    for(int i = 0; i < queriesSize; i++){
        int val = queries[i][0];
        int index = queries[i][1];
        if(nums[index] % 2 == 0){
            sum -= nums[index];
        }
        nums[index] += val;
        if(nums[index] % 2 == 0){
            sum += nums[index];
        }
        result[*returnSize] = sum;
        (*returnSize)++;
    }
    return result;

}

    