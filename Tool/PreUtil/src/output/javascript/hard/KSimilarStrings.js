/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.


/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var kSimilarity = function(s1, s2) {
    let dp = [];
    for(let i = 0; i <= s1.length; i++){
        dp.push([]);
        for(let j = 0; j <= s1.length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= s1.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= s1.length; i++){
        for(let j = 1; j <= s1.length; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= s1.length; i++){
        ans.push(dp[s1.length][i] - dp[s1.length][i - 1]);
    }
    return ans;
    
};

    