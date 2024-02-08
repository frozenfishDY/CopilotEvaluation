/**https://leetcode.com/problems/longest-word-in-dictionary/ */
//Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
//If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
//Note that the word should be built from left to right with each additional character being added to the end of a previous word. 


/**
 * @param {string[]} words
 * @return {string}
 */
var longestWord = function(words) {
    let result = "";
    let set = new Set(words);
    for(let i = 0; i < words.length; i++){
        let temp = words[i];
        let flag = true;
        for(let j = 1; j < temp.length; j++){
            if(!set.has(temp.substring(0, j))){
                flag = false;
                break;
            }
        }
        if(flag){
            if(temp.length > result.length){
                result = temp;
            }else if(temp.length == result.length){
                result = temp.localeCompare(result) < 0 ? temp : result;
            }
        }
    }
    return result;
    
};

    