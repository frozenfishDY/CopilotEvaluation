/**https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/ */
//You are given a list of strings of the same length words and a string target.
//Your task is to form target using the given words under the following rules:
//target should be formed from left to right.
//To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
//Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
//Repeat the process until you form the string target.
//Notice that you can use multiple characters from the same string in words provided the conditions above are met.
//Return the number of ways to form target from words. Since the answer may be too large, return it modulo 10^9 + 7.


/**
 * @param {string[]} words
 * @param {string} target
 * @return {number}
 */
var numWays = function(words, target) {
    let mod = 1000000007;
    let dp = new Array(target.length + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(words[0].length + 1).fill(0);
    }
    let count = new Array(words[0].length + 1).fill(0);
    for(let i = 0; i < words.length; i++){
        for(let j = 0; j < words[0].length; j++){
            if(words[i][j] == target[0]){
                count[j + 1]++;
            }
        }
    }
    for(let i = 1; i <= words[0].length; i++){
        count[i] += count[i - 1];
    }
    dp[0][0] = 1;
    for(let i = 1; i <= target.length; i++){
        for(let j = i; j <= words[0].length; j++){
            let c = 0;
            for(let k = j - 1; k >= i - 1; k--){
                if(words[0][k] == target[i - 1]){
                    c += count[k];
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][k] * c) % mod;
            }
        }
    }
    return dp[target.length][words[0].length];
    
};;

    