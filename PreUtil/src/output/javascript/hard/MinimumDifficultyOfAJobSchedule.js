/**https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/ */
//You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
//You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.
//You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
//Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.


/**
 * @param {number[]} jobDifficulty
 * @param {number} d
 * @return {number}
 */
var minDifficulty = function(jobDifficulty, d) {
    let n = jobDifficulty.length;
    if(n < d) return -1;
    let dp = new Array(d + 1).fill(0).map(() => new Array(n + 1).fill(Infinity));
    dp[0][0] = 0;
    for(let i = 1; i <= d; i++){
        for(let j = i; j <= n; j++){
            let max = 0;
            for(let k = j - 1; k >= i - 1; k--){
                max = Math.max(max, jobDifficulty[k]);
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + max);
            }
        }
    }
    return dp[d][n];
    
};

    