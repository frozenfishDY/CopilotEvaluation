/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSumOfThreeSubarrays = function(nums, k) {
    let n = nums.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= 3; j++){
            dp[i].push([]);
            for(let l = 0; l <= n; l++){
                dp[i][j].push(0);
            }
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][0][0] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= 3; j++){
            for(let l = 1; l <= n; l++){
                if(nums[i - 1] > nums[l - 1]){
                    dp[i][j][l] = dp[i - 1][j - 1][l - 1] + dp[i - 1][j][l];
                }else{
                    dp[i][j][l] = dp[i - 1][j][l];
                }
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= n; i++){
        ans.push(dp[nums.length][3][i] - dp[nums.length][3][i - 1]);
    }
    return ans;
    
};

    