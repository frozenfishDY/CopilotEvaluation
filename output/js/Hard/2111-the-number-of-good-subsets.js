/**https://leetcode.com/problems/the-number-of-good-subsets/ */
//You are given an integer array nums. We call a subset of nums good if its product can be represented as a product of one or more distinct prime numbers.
//For example, if nums = [1, 2, 3, 4]:
//[2, 3], [1, 2, 3], and [1, 3] are good subsets with products 6 = 2*3, 6 = 2*3, and 3 = 3 respectively.
//[1, 4] and [4] are not good subsets with products 4 = 2*2 and 4 = 2*2 respectively.
//Return the number of different good subsets in nums modulo 109 + 7.
//A subset of nums is any array that can be obtained by deleting some (possibly none or all) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.


/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfGoodSubsets = function(nums) {
    let mod = 1000000007;
    let dp = new Array(2).fill(0);
    dp[0] = 1;
    for(let i = 1; i <= nums.length; i++){
        for(let j = 1; j <= 2; j++){
            dp[j] = (dp[j - 1] + (dp[j] * (i - 1)) % mod) % mod;
        }
    }
    return dp[2];

    
};

    