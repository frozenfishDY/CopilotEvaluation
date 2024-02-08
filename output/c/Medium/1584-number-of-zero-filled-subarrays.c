/**https://leetcode.com/problems/number-of-zero-filled-subarrays/ */
//Given an integer array nums, return the number of subarrays filled with 0.
//A subarray is a contiguous non-empty sequence of elements within an array.


long long zeroFilledSubarray(int* nums, int numsSize){
    long long ans = 0;
    int dp[numsSize];
    for(int i=0;i<numsSize;i++){
        dp[i] = 0;
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i] == 0){
            dp[i] = 1;
            if(i > 0){
                dp[i] += dp[i-1];
            }
        }
    }
    for(int i=0;i<numsSize;i++){
        ans += dp[i];
    }
    return ans;

}

    