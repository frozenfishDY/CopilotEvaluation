/**https://leetcode.com/problems/maximum-xor-with-an-element-from-array/ */
//You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].
//The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
//Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maximizeXor(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        arr[i] = 0;
    }
    for(i=1;i<queriesSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<queriesSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return arr;

}

    