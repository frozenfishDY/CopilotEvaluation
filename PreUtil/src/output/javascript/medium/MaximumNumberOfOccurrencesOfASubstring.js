/**https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/ */
//Given a string s, return the maximum number of ocurrences of any substring under the following rules:
//The number of unique characters in the substring must be less than or equal to maxLetters.
//The substring size must be between minSize and maxSize inclusive.


/**
 * @param {string} s
 * @param {number} maxLetters
 * @param {number} minSize
 * @param {number} maxSize
 * @return {number}
 */
var maxFreq = function(s, maxLetters, minSize, maxSize) {
    let result = 0;
    let map = new Map();
    for(let i = 0; i < s.length - minSize + 1; i++){
        let str = s.substring(i, i + minSize);
        if(str.length == new Set(str).size && str.length <= maxLetters){
            if(map.has(str)){
                map.set(str, map.get(str) + 1);
            }else{
                map.set(str, 1);
            }
            result = Math.max(result, map.get(str));
        }
    }
    return result;
    
};

    