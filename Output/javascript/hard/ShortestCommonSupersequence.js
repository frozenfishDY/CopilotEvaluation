/**https://leetcode.com/problems/shortest-common-supersequence/ */
//Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
//A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.


/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var shortestCommonSupersequence = function(str1, str2) {
    let m = str1.length;
    let n = str2.length;
    let dp = new Array(m + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(n + 1).fill(0);
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    let i = m;
    let j = n;
    let ans = '';
    while(i > 0 && j > 0){
        if(str1[i - 1] == str2[j - 1]){
            ans = str1[i - 1] + ans;
            i--;
            j--;
        }
        else{
            if(dp[i - 1][j] > dp[i][j - 1]){
                ans = str1[i - 1] + ans;
                i--;
            }
            else{
                ans = str2[j - 1] + ans;
                j--;
            }
        }
    }
    while(i > 0){
        ans = str1[i - 1] + ans;
        i--;
    }
    while(j > 0){
        ans = str2[j - 1] + ans;
        j--;
    }
    return ans;
    
};

    