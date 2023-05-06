/**https://leetcode.com/problems/regular-expression-matching/ */
//Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
//'.' Matches any single character
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).


/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    let reg = new RegExp(p);
    return reg.test(s);
    
};

    