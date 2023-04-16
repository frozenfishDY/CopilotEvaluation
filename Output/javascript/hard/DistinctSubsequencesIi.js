/**https://leetcode.com/problems/distinct-subsequences-ii/ */
//Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.


/**
 * @param {string} s
 * @return {number}
 */
var distinctSubseqII = function(s) {
    let dp = [];
    for(let i = 0; i <= s.length; i++){
        dp.push([]);
        for(let j = 0; j <= s.length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= s.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= s.length; i++){
        for(let j = 1; j <= s.length; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= s.length; i++){
        ans.push(dp[s.length][i] - dp[s.length][i - 1]);
    }
    return ans;
    
};

    