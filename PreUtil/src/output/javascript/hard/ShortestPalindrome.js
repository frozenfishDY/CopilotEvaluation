/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.


/**
 * @param {string} s
 * @return {string}
 */
var shortestPalindrome = function(s) {
    let n = s.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][i] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(s[i - 1] === s[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 2;
            }else{
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    let result = "";
    let i = n;
    let j = n;
    while(i > 0 && j > 0){
        if(s[i - 1] === s[j - 1]){
            result = s[i - 1] + result;
            i--;
            j--;
        }else{
            if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }else{
                j--;
            }
        }
    }
    return result;
    
};

    