/**https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/ */
//Given an integer n, you must transform it into 0 using the following operations any number of times:
//Change the rightmost (0th) bit in the binary representation of n.
//Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
//Return the minimum number of operations to transform n into 0.


/**
 * @param {number} n
 * @return {number}
 */
var minimumOneBitOperations = function(n) {
    let dp = new Array(n + 1).fill(0);
    for(let i = 1; i <= n; i++){
        dp[i] = dp[i - 1] ^ i;
    }
    return dp[n];
    
};

    