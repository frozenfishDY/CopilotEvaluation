/**https://leetcode.com/problems/number-of-ways-to-separate-numbers/ */
//You wrote down many positive integers in a string called num. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was non-decreasing and that no integer had leading zeros.
//Return the number of possible lists of integers that you could have written down to get the string num. Since the answer may be large, return it modulo 109 + 7.


/**
 * @param {string} num
 * @return {number}
 */
var numberOfCombinations = function(num) {
    let mod = 1000000007;
    let dp = new Array(num.length + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(2).fill(0);
    }
    dp[0][0] = 1;
    for(let i = 1; i <= num.length; i++){
        for(let j = 1; j <= 2; j++){
            dp[i][j] = (dp[i - 1][j - 1] + (dp[i - 1][j] * (i - 1)) % mod) % mod;
        }
    }
    return dp[num.length][2];
    
};

    