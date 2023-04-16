/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/ */
//Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
//Return the maximum possible product of the lengths of the two palindromic subsequences.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.


/**
 * @param {string} s
 * @return {number}
 */
var maxProduct = function(s) {
    let n = s.length;
    let dp = new Array(1 << n).fill(0);
    let result = 0;
    for (let i = 0; i < 1 << n; i++) {
        let str = '';
        for (let j = 0; j < n; j++) {
            if (i & (1 << j)) {
                str += s[j];
            }
        }
        if (isPalindrome(str)) {
            dp[i] = str.length;
        }
    }
    for (let i = 0; i < 1 << n; i++) {
        for (let j = i; j > 0; j = (j - 1) & i) {
            result = Math.max(result, dp[i] * dp[j]);
        }
    }
    return result;
    
    
};

    