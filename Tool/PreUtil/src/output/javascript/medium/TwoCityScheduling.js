/**https://leetcode.com/problems/two-city-scheduling/ */
//A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
//Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.


/**
 * @param {number[][]} costs
 * @return {number}
 */
var twoCitySchedCost = function(costs) {
    let n = costs.length;
    let dp = new Array(n + 1).fill(0);
    for(let i = 1; i <= n; i++){
        dp[i] = costs[i - 1][0] + dp[i - 1];
    }
    for(let i = 1; i <= n; i++){
        for(let j = i; j >= 1; j--){
            dp[j] = Math.min(dp[j], dp[j - 1] + costs[i - 1][1] - costs[i - 1][0]);
        }
    }
    return dp[n / 2];
    

};

    