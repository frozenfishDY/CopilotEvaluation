/**https://leetcode.com/problems/number-of-unique-good-subsequences/ */
//You are given a binary string binary. A subsequence of binary is considered good if it is not empty and has no leading zeros (with the exception of "0").
//Find the number of unique good subsequences of binary.
//For example, if binary = "001", then all the good subsequences are ["0", "0", "1"], so the unique good subsequences are "0" and "1". Note that subsequences "00", "01", and "001" are not good because they have leading zeros.
//Return the number of unique good subsequences of binary. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


/**
 * @param {string} binary
 * @return {number}
 */
var numberOfUniqueGoodSubsequences = function(binary) {
    let mod = 1000000007;
    let dp = new Array(binary.length + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(2).fill(0);
    }
    dp[0][0] = 1;
    for(let i = 1; i <= binary.length; i++){
        for(let j = 1; j <= 2; j++){
            dp[i][j] = (dp[i - 1][j - 1] + (dp[i - 1][j] * (i - 1)) % mod) % mod;
        }
    }
    return dp[binary.length][2];
    
};

    