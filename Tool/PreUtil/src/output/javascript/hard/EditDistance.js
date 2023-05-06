/**https://leetcode.com/problems/edit-distance/ */
//Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
//You have the following three operations permitted on a word:
//Insert a character
//Delete a character
//Replace a character


/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    let m = word1.length;
    let n = word2.length;
    let dp = [];
    for(let i = 0; i <= m; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= m; i++){
        dp[i][0] = i;
    }
    for(let j = 0; j <= n; j++){
        dp[0][j] = j;
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            if(word1[i - 1] === word2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    return dp[m][n];
    
};

    