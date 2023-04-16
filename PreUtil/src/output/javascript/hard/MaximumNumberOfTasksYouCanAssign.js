/**https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/ */
//You have n tasks and m workers. Each task has a strength requirement stored in a 0-indexed integer array tasks, with the ith task requiring tasks[i] strength to complete. The strength of each worker is stored in a 0-indexed integer array workers, with the jth worker having workers[j] strength. Each worker can only be assigned to a single task and must have a strength greater than or equal to the task's strength requirement (i.e., workers[j] >= tasks[i]).
//Additionally, you have pills magical pills that will increase a worker's strength by strength. You can decide which workers receive the magical pills, however, you may only give each worker at most one magical pill.
//Given the 0-indexed integer arrays tasks and workers and the integers pills and strength, return the maximum number of tasks that can be completed.


/**
 * @param {number[]} tasks
 * @param {number[]} workers
 * @param {number} pills
 * @param {number} strength
 * @return {number}
 */
var maxTaskAssign = function(tasks, workers, pills, strength) {
    let n = tasks.length;
    let m = workers.length;
    let dp = new Array(n + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(m + 1).fill(0);
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            if(tasks[i - 1] <= workers[j - 1]){
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
        }
    }
    let ans = dp[n][m];
    let max = 0;
    for(let i = 0; i < m; i++){
        max = Math.max(max, workers[i]);
    }
    for(let i = 0; i <= pills; i++){
        let cur = i * strength + max;
        let count = 0;
        for(let j = 0; j < n; j++){
            if(tasks[j] <= cur){
                count++;
            }
        }
        ans = Math.max(ans, count);
    }
    return ans;
    
};

    