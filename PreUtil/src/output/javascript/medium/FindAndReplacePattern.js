/**https://leetcode.com/problems/find-and-replace-pattern/ */
//Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
//A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.


/**
 * @param {string[]} words
 * @param {string} pattern
 * @return {string[]}
 */
var findAndReplacePattern = function(words, pattern) {
    let result = [];
    for(let i = 0; i < words.length; i++){
        let word = words[i];
        let map = {};
        let visited = new Set();
        let flag = true;
        for(let j = 0; j < word.length; j++){
            if(map[word[j]] == null){
                if(visited.has(pattern[j])){
                    flag = false;
                    break;
                }
                map[word[j]] = pattern[j];
                visited.add(pattern[j]);
            }else{
                if(map[word[j]] != pattern[j]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            result.push(word);
        }
    }
    return result;
    
};

    