/**https://leetcode.com/problems/number-of-ways-to-split-a-string/ */
//Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.
//Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.


/**
 * @param {string} s
 * @return {number}
 */
var numWays = function(s) {
    let n = s.length;
    let mod = 1000000007;
    let ones = 0;
    for (let i = 0; i < n; i++) {
        if (s[i] === '1') {
            ones++;
        }
    }
    if (ones === 0) {
        return (n - 1) * (n - 2) / 2 % mod;
    }
    if (ones % 3 !== 0) {
        return 0;
    }
    let count = 0;
    let res = 0;
    let first = ones / 3;
    let second = ones / 3 * 2;
    for (let i = 0; i < n; i++) {
        if (s[i] === '1') {
            count++;
        }
        if (count === first) {
            res++;
        }
        if (count === second) {
            res++;
        }
    }
    return res % mod;
    
};

    