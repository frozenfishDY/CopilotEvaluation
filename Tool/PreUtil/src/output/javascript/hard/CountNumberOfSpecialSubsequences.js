/**https://leetcode.com/problems/count-number-of-special-subsequences/ */
//A sequence is special if it consists of a positive number of 0s, followed by a positive number of 1s, then a positive number of 2s.
//For example, [0,1,2] and [0,0,1,1,1,2] are special.
//In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
//Given an array nums (consisting of only integers 0, 1, and 2), return the number of different subsequences that are special. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. Two subsequences are different if the set of indices chosen are different.


/**
 * @param {number[]} nums
 * @return {number}
 */
var countSpecialSubsequences = function(nums) {
    let mod = 1000000007;
    let dp = new Array(nums.length + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(3).fill(0);
    }
    for(let i = 0; i < nums.length; i++){
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
        dp[i + 1][2] = dp[i][2];
        if(nums[i] == 0){
            dp[i + 1][0] = (dp[i + 1][0] * 2 + 1) % mod;
        }else if(nums[i] == 1){
            dp[i + 1][1] = (dp[i + 1][1] * 2 + dp[i + 1][0]) % mod;
        }else{
            dp[i + 1][2] = (dp[i + 1][2] * 2 + dp[i + 1][1]) % mod;
        }
    }
    return dp[nums.length][2];
    
};

    