/**https://leetcode.com/problems/number-of-beautiful-partitions/ */
//You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.
//A partition of s is called beautiful if:
//s is partitioned into k non-intersecting substrings.
//Each substring has a length of at least minLength.
//Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
//Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.
//A substring is a contiguous sequence of characters within a string.


/**
 * @param {string} s
 * @param {number} k
 * @param {number} minLength
 * @return {number}
 */
var beautifulPartitions = function(s, k, minLength) {
    let mod = 1000000007;
    let n = s.length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(k + 1).fill(0);
    }
    dp[0][0] = 1;
    let isPrime = new Array(10).fill(true);
    isPrime[1] = false;
    for(let i = 2; i < 10; i++){
        if(isPrime[i]){
            for(let j = i * i; j < 10; j += i){
                isPrime[j] = false;
            }
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= k; j++){
            for(let len = minLength; len <= i; len++){
                if(isPrime[s[i - len].charCodeAt(0) - '0'.charCodeAt(0)] && !isPrime[s[i - 1].charCodeAt(0) - '0'.charCodeAt(0)]){
                    dp[i][j] = (dp[i][j] + dp[i - len][j - 1]) % mod;
                }
            }
        }
    }
    return dp[n][k];
    
};

    