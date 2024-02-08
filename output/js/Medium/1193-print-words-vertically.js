/**https://leetcode.com/problems/print-words-vertically/ */
//Given a string s. Return all the words vertically in the same order in which they appear in s.
//Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
//Each word would be put on only one column and that in one column there will be only one word.


/**
 * @param {string} s
 * @return {string[]}
 */
var printVertically = function(s) {
    let words = s.split(" ");
    let maxLen = 0;
    for(let i = 0; i < words.length; i++){
        maxLen = Math.max(maxLen, words[i].length);
    }
    let result = [];
    for(let i = 0; i < maxLen; i++){
        let str = "";
        for(let j = 0; j < words.length; j++){
            if(i < words[j].length){
                str += words[j][i];
            }else{
                str += " ";
            }
        }
        result.push(str);
    }
    for(let i = 0; i < result.length; i++){
        result[i] = result[i].trimEnd();
    }
    return result;
    
};

    