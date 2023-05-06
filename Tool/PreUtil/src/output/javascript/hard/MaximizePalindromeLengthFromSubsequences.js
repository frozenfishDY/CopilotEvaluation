/**https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/ */
//You are given two strings, word1 and word2. You want to construct a string in the following manner:
//Choose some non-empty subsequence subsequence1 from word1.
//Choose some non-empty subsequence subsequence2 from word2.
//Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
//Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.
//A subsequence of a string s is a string that can be made by deleting some (possibly none) characters from s without changing the order of the remaining characters.
//A palindrome is a string that reads the same forward as well as backward.


/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var longestPalindrome = function(word1, word2) {
    let n = word1.length;
    let m = word2.length;
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(m + 1).fill(0);
    }
    for(let i = n - 1; i >= 0; i--){
        for(let j = m - 1; j >= 0; j--){
            if(word1[i] == word2[j]){
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
        }
    }
    let res = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            let len = 0;
            while(i + len < n && j + len < m && word1[i + len] == word2[j + len]){
                len++;
            }
            res = Math.max(res, 2 * len + dp[i + len][j + len]);
        }
    }
    return res;
    
    
};

    