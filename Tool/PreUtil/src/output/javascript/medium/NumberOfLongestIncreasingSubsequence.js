/**https://leetcode.com/problems/number-of-longest-increasing-subsequence/ */
//Given an integer array nums, return the number of longest increasing subsequences.
//Notice that the sequence has to be strictly increasing.


/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumberOfLIS = function(nums) {
    let n = nums.length;
    let dp = new Array(n).fill(0);
    let count = new Array(n).fill(0);
    let max = 0;
    let result = 0;
    for(let i = 0; i < n; i++){
        dp[i] = 1;
        count[i] = 1;
        for(let j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }else if(dp[j] + 1 == dp[i]){
                    count[i] += count[j];
                }
            }
        }
        if(dp[i] > max){
            max = dp[i];
            result = count[i];
        }else if(dp[i] == max){
            result += count[i];
        }
    }
    return result;
    
};

    