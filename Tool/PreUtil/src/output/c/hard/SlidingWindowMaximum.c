/**https://leetcode.com/problems/sliding-window-maximum/ */
//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the max sliding window.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * (numsSize - k + 1));
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

    