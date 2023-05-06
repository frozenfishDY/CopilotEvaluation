/**https://leetcode.com/problems/minimize-maximum-of-array/ */
//You are given a 0-indexed array nums comprising of n non-negative integers.
//In one operation, you must:
//Choose an integer i such that 1 <= i < n and nums[i] > 0.
//Decrease nums[i] by 1.
//Increase nums[i - 1] by 1.
//Return the minimum possible value of the maximum integer of nums after performing any number of operations.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimizeArrayValue = function(nums) {
    let n = nums.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1] + nums[j];
        }
    }
    let result = Number.MAX_VALUE;
    for (let i = 0; i < n; i++) {
        let sum = 0;
        for (let j = i; j < n; j++) {
            sum += nums[j];
            result = Math.min(result, Math.max(dp[0][i - 1] || 0, sum, dp[j + 1][n - 1] || 0));
        }
    }
    return result;
    
};

    