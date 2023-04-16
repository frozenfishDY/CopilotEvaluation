/**https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ */
//Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
//A subarray is a contiguous part of an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var shortestSubarray = function(nums, k) {
    let dp = [];
    for(let i = 0; i <= nums.length; i++){
        dp.push([]);
        for(let j = 0; j <= nums.length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= nums.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= nums.length; i++){
        for(let j = 1; j <= nums.length; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= nums.length; i++){
        ans.push(dp[nums.length][i] - dp[nums.length][i - 1]);
    }
    return ans;
    
};

    