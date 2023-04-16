/**https://leetcode.com/problems/maximum-subarray/ */
//Given an integer array nums, find the subarray with the largest sum, and return its sum.


int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        if(sum > max){
            max = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    return max;

}

    