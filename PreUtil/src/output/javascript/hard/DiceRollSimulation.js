/**https://leetcode.com/problems/dice-roll-simulation/ */
//A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
//Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls. Since the answer may be too large, return it modulo 109 + 7.
//Two sequences are considered different if at least one element differs from each other


/**
 * @param {number} n
 * @param {number[]} rollMax
 * @return {number}
 */
var dieSimulator = function(n, rollMax) {
    let dp = new Array(n + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(6).fill(0);
    }
    for(let i = 0; i < 6; i++){
        dp[1][i] = 1;
    }
    for(let i = 2; i <= n; i++){
        for(let j = 0; j < 6; j++){
            for(let k = 1; k <= rollMax[j]; k++){
                if(i - k >= 0){
                    let sum = 0;
                    for(let l = 0; l < 6; l++){
                        if(l != j){
                            sum = (sum + dp[i - k][l]) % 1000000007;
                        }
                    }
                    dp[i][j] = (dp[i][j] + sum) % 1000000007;
                }
            }
        }
    }
    let ans = 0;
    for(let i = 0; i < 6; i++){
        ans = (ans + dp[n][i]) % 1000000007;
    }
    return ans;
    
};

    