/**https://leetcode.com/problems/total-appeal-of-a-string/ */
//The appeal of a string is the number of distinct characters found in the string.
//For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
//Given a string s, return the total appeal of all of its substrings.
//A substring is a contiguous sequence of characters within a string.


/**
 * @param {string} s
 * @return {number}
 */
var appealSum = function(s) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < s.length; j++) {
            let xor = s[i] ^ s[j];
            if (xor >= low && xor <= high) {
                result++;
            }
        }
    }
    return result;
    
};

    