/**https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/ */
//Given an array of integers arr, return the number of subarrays with an odd sum.
//Since the answer can be very large, return it modulo 109 + 7.


/**
 * @param {number[]} arr
 * @return {number}
 */
var numOfSubarrays = function(arr) {
    let n = arr.length;
    let mod = 1000000007;
    let dp = new Array(n).fill(0);
    let sum = 0;
    let res = 0;
    for (let i = 0; i < n; i++) {
        sum += arr[i];
        if (sum % 2 === 0) {
            dp[i] = 1;
        }
        if (i > 0) {
            dp[i] += dp[i - 1];
        }
        res += dp[i];
        res %= mod;
    }
    return res;
    
};

    