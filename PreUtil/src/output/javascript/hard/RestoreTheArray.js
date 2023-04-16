/**https://leetcode.com/problems/restore-the-array/ */
//A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.
//Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 10^9 + 7.


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var numberOfArrays = function(s, k) {
    let mod = 1000000007;
    let dp = new Array(s.length + 1).fill(0);
    dp[0] = 1;
    for(let i = 1; i <= s.length; i++){
        for(let j = 1; j <= k && j <= i; j++){
            if(s[i - j] == '0'){
                continue;
            }
            let num = parseInt(s.substring(i - j, i));
            if(num <= k){
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    return dp[s.length];
    
};

    