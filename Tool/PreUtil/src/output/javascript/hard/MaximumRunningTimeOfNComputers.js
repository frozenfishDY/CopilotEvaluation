/**https://leetcode.com/problems/maximum-running-time-of-n-computers/ */
//You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.
//Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.
//Note that the batteries cannot be recharged.
//Return the maximum number of minutes you can run all the n computers simultaneously.


/**
 * @param {number} n
 * @param {number[]} batteries
 * @return {number}
 */
var maxRunTime = function(n, batteries) {
    let m = batteries.length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(m + 1).fill(0);
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j - 1] + batteries[j - 1]);
        }
    }
    return dp[n][m];
    
};

    