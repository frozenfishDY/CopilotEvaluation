/**https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/ */
//Given n orders, each order consist in pickup and delivery services. 
//Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 
//Since the answer may be too large, return it modulo 10^9 + 7.


/**
 * @param {number} n
 * @return {number}
 */
var countOrders = function(n) {
    let mod = 1000000007;
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    for(let i = 1; i <= n; i++){
        dp[i] = dp[i - 1] * (2 * i - 1) * (2 * i) % mod;
    }
    return dp[n];
    
};

    