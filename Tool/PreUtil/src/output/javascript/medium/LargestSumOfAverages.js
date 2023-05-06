/**https://leetcode.com/problems/largest-sum-of-averages/ */
//You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
//Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
//Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestSumOfAverages = function(nums, k) {
    let n = nums.length;
    let dp = new Array(n + 1).fill(0);
    let sum = new Array(n + 1).fill(0);
    for(let i = 0; i < n; i++){
        sum[i + 1] = sum[i] + nums[i];
        dp[i + 1] = (sum[i + 1] * 1.0) / (i + 1);
    }
    for(let i = 2; i <= k; i++){
        for(let j = n; j >= i; j--){
            for(let p = i - 1; p < j; p++){
                dp[j] = Math.max(dp[j], dp[p] + (sum[j] - sum[p]) * 1.0 / (j - p));
            }
        }
    }
    return dp[n];
    
};

    