/**https://leetcode.com/problems/most-profit-assigning-work/ */
//You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
//difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
//worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
//Every worker can be assigned at most one job, but one job can be completed multiple times.
//For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
//Return the maximum profit we can achieve after assigning the workers to the jobs.


/**
 * @param {number[]} difficulty
 * @param {number[]} profit
 * @param {number[]} worker
 * @return {number}
 */
var maxProfitAssignment = function(difficulty, profit, worker) {
    let n = difficulty.length;
    let jobs = [];
    for(let i = 0; i < n; i++){
        jobs.push([difficulty[i], profit[i]]);
    }
    jobs.sort((a, b) => a[0] - b[0]);
    let result = 0;
    let maxProfit = 0;
    let i = 0;
    worker.sort((a, b) => a - b);
    for(let ability of worker){
        while(i < n && ability >= jobs[i][0]){
            maxProfit = Math.max(maxProfit, jobs[i][1]);
            i++;
        }
        result += maxProfit;
    }
    return result;
    
};

    