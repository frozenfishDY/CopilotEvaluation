/**https://leetcode.com/problems/longest-substring-of-one-repeating-character/ */
//You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
//The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
//Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.


/**
 * @param {string} s
 * @param {string} queryCharacters
 * @param {number[]} queryIndices
 * @return {number[]}
 */
var longestRepeating = function(s, queryCharacters, queryIndices) {
    let n = s.length;
    let m = queryCharacters.length;
    let ans = new Array(m).fill(0);
    let dp = new Array(n + 1);
    for(let i = 0; i <= n; i++){
        dp[i] = new Array(26).fill(0);
    }
    for(let i = 1; i <= n; i++){
        for(let j = 0; j < 26; j++){
            if(s[i - 1] == String.fromCharCode(97 + j)){
                dp[i][j] = dp[i - 1][j] + 1;
            }else{
                dp[i][j] = 0;
            }
        }
    }
    for(let i = 0; i < m; i++){
        let idx = queryIndices[i] - 1;
        let ch = queryCharacters[i].charCodeAt(0) - 97;
        let max = 0;
        for(let j = 0; j < 26; j++){
            if(j != ch){
                max = Math.max(max, dp[idx + 1][j]);
            }
        }
        ans[i] = max;
    }
    return ans;
    
};

    