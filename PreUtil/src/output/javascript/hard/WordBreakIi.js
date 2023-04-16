/**https://leetcode.com/problems/word-break-ii/ */
//Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
//Note that the same word in the dictionary may be reused multiple times in the segmentation.


/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {string[]}
 */
var wordBreak = function(s, wordDict) {
    let n = s.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < n; j++){
            dp[i].push(false);
        }
    }
    let wordSet = new Set();
    for(let word of wordDict){
        wordSet.add(word);
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j <= i; j++){
            if(wordSet.has(s.substring(j, i + 1)) && (j === 0 || dp[j - 1][i])){
                dp[j][i] = true;
            }
        }
    }
    let result = [];
    let path = [];
    dfs(s, n - 1, dp, path, result);
    return result;
    
    
};

    