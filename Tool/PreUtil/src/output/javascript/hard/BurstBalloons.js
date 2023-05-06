/**https://leetcode.com/problems/burst-balloons/ */
//You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
//If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
//Return the maximum coins you can collect by bursting the balloons wisely.


/**
 * @param {number[]} nums
 * @return {number}
 */
var maxCoins = function(nums) {
    let n = nums.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(i - j >= 0){
                let left = 1;
                let right = 1;
                if(i - j - 1 >= 0){
                    left = nums[i - j - 1];
                }
                if(i < n){
                    right = nums[i];
                }
                dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - 1] + left * nums[i - j] * right);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][n];
    
};

    