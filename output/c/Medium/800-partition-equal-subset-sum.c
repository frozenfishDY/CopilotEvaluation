/**https://leetcode.com/problems/partition-equal-subset-sum/ */
//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    int target = sum / 2;
    bool* dp = (bool*)malloc(sizeof(bool) * (target + 1));
    for(int i = 0; i <= target; i++){
        dp[i] = false;
    }
    dp[0] = true;
    for(int i = 0; i < numsSize; i++){
        for(int j = target; j >= nums[i]; j--){
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[target];

}

    