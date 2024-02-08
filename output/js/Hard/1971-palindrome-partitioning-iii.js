/**https://leetcode.com/problems/palindrome-partitioning-iii/ */
//You are given a string s containing lowercase letters and an integer k. You need to :
//First, change some characters of s to other lowercase English letters.
//Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
//Return the minimal number of characters that you need to change to divide the string.


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var palindromePartition = function(s, k) {
    let n = s.length;
    let dp = new Array(n + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(k + 1).fill(0);
    }
    let cost = new Array(n + 1);
    for(let i = 0; i < cost.length; i++){
        cost[i] = new Array(n + 1).fill(0);
    }
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            let l = i;
            let r = j;
            while(l < r){
                if(s[l] != s[r]){
                    cost[i][j]++;
                }
                l++;
                r--;
            }
        }
    }
    for(let i = 1; i <= n; i++){
        dp[i][1] = cost[0][i - 1];
    }
    for(let i = 1; i <= n; i++){
        for(let j = 2; j <= k; j++){
            dp[i][j] = Infinity;
            for(let l = 1; l <= i; l++){
                dp[i][j] = Math.min(dp[i][j], dp[l][j - 1] + cost[l][i - 1]);
            }
        }
    }
    return dp[n][k];
    
};

    