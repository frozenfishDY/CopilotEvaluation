/**https://leetcode.com/problems/minimum-cost-to-merge-stones/ */
//There are n piles of stones arranged in a row. The ith pile has stones[i] stones.
//A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.
//Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.


/**
 * @param {number[]} stones
 * @param {number} k
 * @return {number}
 */
var mergeStones = function(stones, k) {
    let n = stones.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let l = 0; l <= k; l++){
                dp[i][j].push(0);
            }
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][i][1] = 0;
    }
    for(let i = 1; i <= n; i++){
        for(let j = i - 1; j >= 0; j--){
            for(let l = 2; l <= k; l++){
                dp[i][j][l] = Number.MAX_SAFE_INTEGER;
                for(let m = j; m < i; m++){
                    dp[i][j][l] = Math.min(dp[i][j][l], dp[m][j][1] + dp[i][m + 1][l - 1]);
                }
            }
            dp[i][j][1] = dp[i][j][k] + sum(stones, j, i);
        }
    }
    return dp[n][0][1] === Number.MAX_SAFE_INTEGER ? -1 : dp[n][0][1];
    
    
};

    