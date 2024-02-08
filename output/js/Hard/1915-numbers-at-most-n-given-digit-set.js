/**https://leetcode.com/problems/numbers-at-most-n-given-digit-set/ */
//Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
//Return the number of positive integers that can be generated that are less than or equal to a given integer n.


/**
 * @param {string[]} digits
 * @param {number} n
 * @return {number}
 */
var atMostNGivenDigitSet = function(digits, n) {
    let dp = [];
    for(let i = 0; i <= digits.length; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= digits.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= digits.length; i++){
        for(let j = 1; j <= n; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[digits.length][n];
    
};

    