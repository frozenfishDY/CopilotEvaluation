/**https://leetcode.com/problems/count-ways-to-build-good-strings/ */
//Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
//Append the character '0' zero times.
//Append the character '1' one times.
//This can be performed any number of times.
//A good string is a string constructed by the above process having a length between low and high (inclusive).
//Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.


/**
 * @param {number} low
 * @param {number} high
 * @param {number} zero
 * @param {number} one
 * @return {number}
 */
var countGoodStrings = function(low, high, zero, one) {
    let mod = 1000000007;
    let n = high.length;
    let dp = new Array(n + 1).fill(0);
    dp[0] = 1;
    for (let i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * (zero + one) % mod;
    }
    let res = 0;
    for (let i = 0; i < n; i++) {
        let l = low[i] - '0';
        let h = high[i] - '0';
        if (l === 0) {
            res += dp[n - i - 1] * zero % mod;
        } else {
            res += dp[n - i - 1] * one % mod;
        }
        res %= mod;
        if (l === h) {
            if (l === 0) {
                zero--;
            } else {
                one--;
            }
        } else {
            break;
        }
    }
    return res;
    
};

    