/**https://leetcode.com/problems/minimize-maximum-of-array/ */
//You are given a 0-indexed array nums comprising of n non-negative integers.
//In one operation, you must:
//Choose an integer i such that 1 <= i < n and nums[i] > 0.
//Decrease nums[i] by 1.
//Increase nums[i - 1] by 1.
//Return the minimum possible value of the maximum integer of nums after performing any number of operations.


int minimizeArrayValue(int* nums, int numsSize){
    int dp[numsSize];
    for(int i=0;i<numsSize;i++){
        dp[i] = 0;
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i] > 0){
            dp[i] = nums[i];
            if(i > 0){
                dp[i] += dp[i-1];
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<numsSize;i++){
        ans = min(ans, dp[i]);
    }
    return ans;

}

    