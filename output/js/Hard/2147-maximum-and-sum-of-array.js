/**https://leetcode.com/problems/maximum-and-sum-of-array/ */
//You are given an integer array nums of length n and an integer numSlots such that 2 * numSlots >= n. There are numSlots slots numbered from 1 to numSlots.
//You have to place all n integers into the slots such that each slot contains at most two numbers. The AND sum of a given placement is the sum of the bitwise AND of every number with its respective slot number.
//For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6] into slot 2 is equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4.
//Return the maximum possible AND sum of nums given numSlots slots.


/**
 * @param {number[]} nums
 * @param {number} numSlots
 * @return {number}
 */
var maximumANDSum = function(nums, numSlots) {
    let n = nums.length;
    let dp = new Array(n + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(numSlots + 1).fill(0);
    }
    let sum = new Array(n + 1);
    sum[0] = 0;
    for(let i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + nums[i - 1];
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= numSlots; j++){
            dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - 1] + (nums[i - 1] & j));
        }
    }
    return dp[n][numSlots];
    
};

    