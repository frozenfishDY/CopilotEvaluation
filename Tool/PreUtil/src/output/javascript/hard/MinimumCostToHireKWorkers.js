/**https://leetcode.com/problems/minimum-cost-to-hire-k-workers/ */
//There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
//We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
//Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
//Every worker in the paid group must be paid at least their minimum wage expectation.
//Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.


/**
 * @param {number[]} quality
 * @param {number[]} wage
 * @param {number} k
 * @return {number}
 */
var mincostToHireWorkers = function(quality, wage, k) {
    let n = quality.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= k; j++){
            dp[i].push(0);
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= k; j++){
            if(i - j >= 0){
                dp[i][j] = Math.max(dp[i - 1][j], quality[i - 1]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = k; i <= n; i++){
        ans.push(dp[i][k]);
    }
    return ans;
    
};

    