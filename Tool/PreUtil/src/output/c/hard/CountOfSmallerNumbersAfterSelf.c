/**https://leetcode.com/problems/count-of-smaller-numbers-after-self/ */
//Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int* queue = (int*)malloc(sizeof(int) * numsSize);
    int head = 0, tail = 0;
    for(int i = numsSize - 1; i >= 0; i--){
        while(head < tail && nums[queue[tail - 1]] >= nums[i]) tail--;
        result[i] = tail;
        queue[tail++] = i;
    }
    *returnSize = numsSize;
    return result;


}

    