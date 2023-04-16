/**https://leetcode.com/problems/substring-with-concatenation-of-all-words/ */
//You are given a string s and an array of strings words. All the strings of words are of the same length.
//A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
//For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
//Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.


/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    let res = [];
    let len = words.length;
    if (len == 0) {
        return res;
    }
    let wordLen = words[0].length;
    let totalLen = len * wordLen;
    let map = {};
    for (let i = 0; i < len; i++) {
        if (map[words[i]]) {
            map[words[i]]++;
        } else {
            map[words[i]] = 1;
        }
    }
    for (let i = 0; i < s.length - totalLen + 1; i++) {
        let tempMap = {};
        let j = 0;
        for (; j < len; j++) {
            let word = s.substring(i + j * wordLen, i + (j + 1) * wordLen);
            if (map[word]) {
                if (tempMap[word]) {
                    tempMap[word]++;
                } else {
                    tempMap[word] = 1;
                }
                if (tempMap[word] > map[word]) {
                    break;
                }
            } else {
                break;
            }
        }
        if (j == len) {
            res.push(i);
        }
    }
    return res;
    
};

    