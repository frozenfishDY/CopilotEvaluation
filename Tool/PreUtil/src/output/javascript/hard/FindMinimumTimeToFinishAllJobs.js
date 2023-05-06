/**https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/ */
//You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.
//There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.
//Return the minimum possible maximum working time of any assignment.


/**
 * @param {number[]} jobs
 * @param {number} k
 * @return {number}
 */
var minimumTimeRequired = function(jobs, k) {
    let n = jobs.length;
    let m = 1 << n;
    let dp = new Array(m).fill(0);
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if((i & (1 << j)) != 0){
                dp[i] += jobs[j];
            }
        }
    }
    let dp2 = new Array(m).fill(0);
    for(let i = 0; i < m; i++){
        for(let j = i; j > 0; j = (j - 1) & i){
            dp2[i] = Math.max(dp2[i], Math.min(dp[j], dp[i - j]));
        }
    }
    let dp3 = new Array(k).fill(0);
    for(let i = 0; i < m; i++){
        let next = dp3.slice();
        for(let j = 0; j < k; j++){
            next[j] = Math.max(dp3[j], dp2[i]);
        }
        dp3 = next;
    }
    return dp3[k - 1];
    
};

    