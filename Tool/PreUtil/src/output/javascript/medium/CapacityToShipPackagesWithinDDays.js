/**https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ */
//A conveyor belt has packages that must be shipped from one port to another within days days.
//The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
//Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


/**
 * @param {number[]} weights
 * @param {number} days
 * @return {number}
 */
var shipWithinDays = function(weights, days) {
    let n = weights.length;
    let dp = new Array(n + 1).fill(0).map(() => new Array(days + 1).fill(0));
    let sum = 0;
    for(let i = 1; i <= n; i++){
        sum += weights[i - 1];
        dp[i][1] = sum;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 2; j <= days; j++){
            if(j > i){
                dp[i][j] = dp[i][j - 1];
            }else{
                let min = Number.MAX_SAFE_INTEGER;
                let sum = 0;
                for(let k = i; k >= 1; k--){
                    sum += weights[k - 1];
                    min = Math.min(min, Math.max(dp[k - 1][j - 1], sum));
                }
                dp[i][j] = min;
            }
        }
    }
    return dp[n][days];
    
};

    