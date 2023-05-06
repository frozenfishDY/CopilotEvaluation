/**https://leetcode.com/problems/maximum-profit-in-job-scheduling/ */
//We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
//You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
//If you choose a job that ends at time X you will be able to start another job that starts at time X.


/**
 * @param {number[]} startTime
 * @param {number[]} endTime
 * @param {number[]} profit
 * @return {number}
 */
var jobScheduling = function(startTime, endTime, profit) {
    let n = startTime.length;
    let jobs = [];
    for(let i = 0; i < n; i++){
        jobs.push([startTime[i], endTime[i], profit[i]]);
    }
    jobs.sort((a, b) => a[1] - b[1]);
    let dp = new Array(n + 1).fill(0);
    for(let i = 1; i <= n; i++){
        let [start, end, profit] = jobs[i - 1];
        let index = binarySearch(jobs, start);
        dp[i] = Math.max(dp[i - 1], profit + dp[index]);
    }
    return dp[n];
    
    
};

    