/**https://leetcode.com/problems/partition-equal-subset-sum/ */
//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    let n = nums.length;
    let sum = 0;
    for(let i = 0; i < n; i++){
        sum += nums[i];
    }
    if(sum % 2 == 1){
        return false;
    }
    sum /= 2;
    let dp = new Array(n + 1).fill(false);
    dp[0] = true;
    for(let i = 0; i < n; i++){
        for(let j = sum; j >= nums[i]; j--){
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[sum];
    
};

    