/**https://leetcode.com/problems/closest-subsequence-sum/ */
//You are given an integer array nums and an integer goal.
//You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
//Return the minimum possible value of abs(sum - goal).
//Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.


/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var minAbsDifference = function(nums, goal) {
    let n = nums.length;
    let m = 1 << n;
    let dp = new Array(m).fill(0);
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if((i & (1 << j)) != 0){
                dp[i] += nums[j];
            }
        }
    }
    dp.sort((a, b) => a - b);
    let res = Infinity;
    for(let i = 0; i < m; i++){
        let sum = dp[i];
        let idx = binarySearch(dp, goal - sum);
        res = Math.min(res, Math.abs(sum + dp[idx] - goal));
        if(idx > 0){
            res = Math.min(res, Math.abs(sum + dp[idx - 1] - goal));
        }
    }
    return res;
    
    
};

    