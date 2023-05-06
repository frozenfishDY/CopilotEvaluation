/**https://leetcode.com/problems/constrained-subsequence-sum/ */
//Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
//A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var constrainedSubsetSum = function(nums, k) {
    let n = nums.length;
    let dp = new Array(n).fill(0);
    dp[0] = nums[0];
    let ans = dp[0];
    let q = [];
    q.push(0);
    for(let i = 1; i < n; i++){
        dp[i] = nums[i];
        if(q.length > 0 && i - q[0] <= k){
            dp[i] = Math.max(dp[i], dp[q[0]] + nums[i]);
        }
        while(q.length > 0 && dp[q[q.length - 1]] <= dp[i]){
            q.pop();
        }
        q.push(i);
        ans = Math.max(ans, dp[i]);
    }
    return ans;
    
};

    