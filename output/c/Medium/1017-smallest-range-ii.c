/**https://leetcode.com/problems/smallest-range-ii/ */
//You are given an integer array nums and an integer k.
//For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.
//The score of nums is the difference between the maximum and minimum elements in nums.
//Return the minimum score of nums after changing the values at each index.


int smallestRangeII(int* nums, int numsSize, int k){
    int result = 0;
    int dp[numsSize];
    for(int i = 0; i < numsSize; i++){
        dp[i] = 0;
    }
    for(int i = 1; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] == nums[j] * nums[j]){
                dp[i] = dp[j] + 1;
                result = result > dp[i] ? result : dp[i];
            }
        }
    }
    return result == 0 ? -1 : result + 1;

}

    