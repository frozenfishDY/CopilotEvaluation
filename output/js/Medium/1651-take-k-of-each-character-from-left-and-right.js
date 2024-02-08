/**https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/ */
//You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
//Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var takeCharacters = function(s, k) {
    let n = s.length;
    let dp = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(s[i - 1] == s[n - j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    let lcs = dp[n][n];
    if(lcs >= k){
        return 2 * (n - lcs);
    }else{
        return -1;
    }
    
};

    