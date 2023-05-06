/**https://leetcode.com/problems/palindrome-pairs/ */
//You are given a 0-indexed array of unique strings words.
//A palindrome pair is a pair of integers (i, j) such that:
//0 <= i, j < words.length,
//i != j, and
//words[i] + words[j] (the concatenation of the two strings) is a palindrome.
//Return an array of all the palindrome pairs of words.


/**
 * @param {string[]} words
 * @return {number[][]}
 */
var palindromePairs = function(words) {
    let n = words.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(false);
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(i !== j){
                dp[i][j] = isPalindrome(words[i - 1] + words[j - 1]);
            }
        }
    }
    let result = [];
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(dp[i][j]){
                result.push([i - 1, j - 1]);
            }
        }
    }
    return result;
    
    
};

    