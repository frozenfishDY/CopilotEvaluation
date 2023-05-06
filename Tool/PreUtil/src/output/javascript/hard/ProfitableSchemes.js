/**https://leetcode.com/problems/profitable-schemes/ */
//There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.
//Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.
//Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 10^9 + 7.


/**
 * @param {number} n
 * @param {number} minProfit
 * @param {number[]} group
 * @param {number[]} profit
 * @return {number}
 */
var profitableSchemes = function(n, minProfit, group, profit) {
    let m = group.length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push([]);
            for(let k = 0; k <= minProfit; k++){
                dp[i][j].push(0);
            }
        }
    }
    for(let i = 0; i <= m; i++){
        dp[i][0][0] = 1;
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            for(let k = 0; k <= minProfit; k++){
                dp[i][j][k] = dp[i - 1][j][k];
                if(j >= group[i - 1]){
                    dp[i][j][k] += dp[i - 1][j - group[i - 1]][Math.max(0, k - profit[i - 1])];
                    dp[i][j][k] %= 1000000007;
                }
            }
        }
    }
    let res = 0;
    for(let i = 0; i <= n; i++){
        res += dp[m][i][minProfit];
        res %= 1000000007;
    }
    return res;
    
};

    