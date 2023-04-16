/**https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/ */
//You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).
//Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 10^9 + 7.


/**
 * @param {number} steps
 * @param {number} arrLen
 * @return {number}
 */
var numWays = function(steps, arrLen) {
    let dp = new Array(steps + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(arrLen).fill(0);
    }
    dp[0][0] = 1;
    for(let i = 1; i <= steps; i++){
        for(let j = 0; j < arrLen; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - 1 >= 0){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000007;
            }
            if(j + 1 < arrLen){
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000007;
            }
        }
    }
    return dp[steps][0];
    
};

    