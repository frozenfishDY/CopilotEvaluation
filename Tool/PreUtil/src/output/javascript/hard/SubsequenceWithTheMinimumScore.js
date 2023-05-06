/**https://leetcode.com/problems/subsequence-with-the-minimum-score/ */
//You are given two strings s and t.
//You are allowed to remove any number of characters from the string t.
//The score of the string is 0 if no characters are removed from the string t, otherwise:
//Let left be the minimum index among all removed characters.
//Let right be the maximum index among all removed characters.
//Then the score of the string is right - left + 1.
//Return the minimum possible score to make t a subsequence of s.
//A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minimumScore = function(s, t) {
    let n = s.length;
    let m = t.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= m; j++){
            dp[i].push(0);
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            if(s[i - 1] === t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    let result = 0;
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            if(dp[i][j] === dp[n][m]){
                result = Math.max(result, i - j + 1);
            }
        }
    }
    return result;
    
};

    