/**https://leetcode.com/problems/maximum-product-of-word-lengths/ */
//Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.


/**
 * @param {string[]} words
 * @return {number}
 */
var maxProduct = function(words) {
    let n = words.length;
    let result = 0;
    let masks = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        for(let j = 0; j < words[i].length; j++){
            masks[i] |= 1 << (words[i].charCodeAt(j) - 97);
        }
    }
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            if((masks[i] & masks[j]) == 0){
                result = Math.max(result, words[i].length * words[j].length);
            }
        }
    }
    return result;
    
};

    