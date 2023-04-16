/**https://leetcode.com/problems/house-robber-ii/ */
//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
//Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let n = nums.length;
    if(n == 1){
        return nums[0];
    }
    let dp = new Array(n + 1).fill(0);
    for(let i = 1; i <= n; i++){
        dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    let dp2 = new Array(n + 1).fill(0);
    for(let i = 2; i <= n; i++){
        dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
    }
    return Math.max(dp[n - 1], dp2[n]);
    
};

    