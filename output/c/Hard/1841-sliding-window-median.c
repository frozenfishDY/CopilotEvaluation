/**https://leetcode.com/problems/sliding-window-median/ */
//The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.
//For examples, if arr = [2,3,4], the median is 3.
//For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
//You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    double* result = (double*)malloc(sizeof(double) * (numsSize - k + 1));
    int* queue = (int*)malloc(sizeof(int) * numsSize);
    int head = 0, tail = 0;
    for(int i = 0; i < numsSize; i++){
        while(head < tail && nums[queue[tail - 1]] < nums[i]) tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k) head++;
        if(i >= k - 1){
            if(k % 2 == 0){
                result[i - k + 1] = (nums[queue[head]] + nums[queue[head + 1]]) / 2.0;
            }else{
                result[i - k + 1] = nums[queue[head]];
            }
        }
    }
    *returnSize = numsSize - k + 1;
    return result;

}

    