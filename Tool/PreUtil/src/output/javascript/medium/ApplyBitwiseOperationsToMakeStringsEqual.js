/**https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/ */
//You are given two 0-indexed binary strings s and target of the same length n. You can do the following operation on s any number of times:
//Choose two different indices i and j where 0 <= i, j < n.
//Simultaneously, replace s[i] with (s[i] OR s[j]) and s[j] with (s[i] XOR s[j]).
//For example, if s = "0110", you can choose i = 0 and j = 2, then simultaneously replace s[0] with (s[0] OR s[2] = 0 OR 1 = 1), and s[2] with (s[0] XOR s[2] = 0 XOR 1 = 1), so we will have s = "1110".
//Return true if you can make the string s equal to target, or false otherwise.


/**
 * @param {string} s
 * @param {string} target
 * @return {boolean}
 */
var makeStringsEqual = function(s, target) {
    let s1 = 0;
    let s2 = 0;
    for(let i = 0; i < s.length; i++){
        s1 += s[i].charCodeAt(0) - 'a'.charCodeAt(0);
        s2 += target[i].charCodeAt(0) - 'a'.charCodeAt(0);
    }
    return s1 == s2;
    
};

    