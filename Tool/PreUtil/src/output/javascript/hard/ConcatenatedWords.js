/**https://leetcode.com/problems/concatenated-words/ */
//Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necesssarily distinct) in the given array.


/**
 * @param {string[]} words
 * @return {string[]}
 */
var findAllConcatenatedWordsInADict = function(words) {
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
                dp[i][j] = isConcatenated(words[i - 1], words[j - 1]);
            }
        }
    }
    let result = [];
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(dp[i][j]){
                result.push(words[i - 1]);
            }
        }
    }
    return result;
    
    
    
};

    