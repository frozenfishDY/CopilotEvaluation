/**https://leetcode.com/problems/detect-capital/ */
//We define the usage of capitals in a word to be right when one of the following cases holds:
//All letters in this word are capitals, like "USA".
//All letters in this word are not capitals, like "leetcode".
//Only the first letter in this word is capital, like "Google".
//Given a string word, return true if the usage of capitals in it is right.


/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function(word) {
    let len = word.length;
    let first = word[0];
    let second = word[1];
    if(first == first.toUpperCase() && second == second.toUpperCase()){
        for(let i = 2; i < len; i++){
            if(word[i] != word[i].toUpperCase()){
                return false;
            }
        }
    }else if(first == first.toUpperCase() && second == second.toLowerCase()){
        for(let i = 2; i < len; i++){
            if(word[i] != word[i].toLowerCase()){
                return false;
            }
        }
    }else{
        for(let i = 1; i < len; i++){
            if(word[i] != word[i].toLowerCase()){
                return false;
            }
        }
    }
    return true;
    
};

    