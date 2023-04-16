/**https://leetcode.com/problems/number-of-matching-subsequences/ */
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//For example, "ace" is a subsequence of "abcde".


/**
 * @param {string} s
 * @param {string[]} words
 * @return {number}
 */
var numMatchingSubseq = function(s, words) {
    let n = s.length;
    let m = words.length;
    let index = new Array(26);
    for(let i = 0; i < 26; i++){
        index[i] = [];
    }
    for(let i = 0; i < n; i++){
        index[s.charCodeAt(i) - 97].push(i);
    }
    let result = 0;
    for(let i = 0; i < m; i++){
        let prev = -1;
        let flag = true;
        for(let j = 0; j < words[i].length; j++){
            let char = words[i].charCodeAt(j) - 97;
            let pos = binarySearch(index[char], prev);
            if(pos == index[char].length){
                flag = false;
                break;
            }
            prev = index[char][pos];
        }
        if(flag){
            result++;
        }
    }
    return result;
    
    
};

    