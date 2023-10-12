/**https://leetcode.com/problems/reformat-the-string/ */
//You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
//You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
//Return the reformatted string or return an empty string if it is impossible to reformat the string.
// 
//Example 1:
//Input: s = "a0b1c2"
//Output: "0a1b2c"
//Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
//Example 2:
//Input: s = "leetcode"
//Output: ""
//Explanation: "leetcode" has only characters so we cannot separate them by digits.
//Example 3:
//Input: s = "1229857369"
//Output: ""
//Explanation: "1229857369" has only digits so we cannot separate them by characters.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and/or digits.
/**
 * @param {string} s
 * @return {string}
 */
var reformat = function(s) {
    let num = [];
    let letter = [];
    for (let i = 0; i < s.length; i++) {
        if (Number.isInteger(parseInt(s[i]))) num.push(s[i]);
        else letter.push(s[i]);
    }
    if (Math.abs(num.length - letter.length) > 1) return '';
    let res = '';
    if (num.length > letter.length) {
        for (let i = 0; i < num.length; i++) {
            res += num[i];
            if (i < letter.length) res += letter[i];
        }
    } else {
        for (let i = 0; i < letter.length; i++) {
            res += letter[i];
            if (i < num.length) res += num[i];
        }
    }
    return res;
};