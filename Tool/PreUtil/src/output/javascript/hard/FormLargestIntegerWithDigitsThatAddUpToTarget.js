/**https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/ */
//Given an array of integers cost and an integer target, return the maximum integer you can paint under the following rules:
//The cost of painting a digit (i + 1) is given by cost[i] (0-indexed).
//The total cost used must be equal to target.
//The integer does not have 0 digits.
//Since the answer may be very large, return it as a string. If there is no way to paint any integer given the condition, return "0".


/**
 * @param {number[]} cost
 * @param {number} target
 * @return {string}
 */
var largestNumber = function(cost, target) {
    let dp = new Array(target + 1).fill(0);
    for(let i = 0; i < cost.length; i++){
        for(let j = cost[i]; j <= target; j++){
            dp[j] = Math.max(dp[j], dp[j - cost[i]] + 1);
        }
    }
    if(dp[target] == 0){
        return "0";
    }
    let res = "";
    for(let i = 8; i >= 0; i--){
        while(target >= cost[i] && dp[target] == dp[target - cost[i]] + 1){
            res += (i + 1);
            target -= cost[i];
        }
    }
    return res;
    
};

    