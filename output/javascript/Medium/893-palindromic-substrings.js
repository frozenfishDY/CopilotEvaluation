/**https://leetcode.com/problems/palindromic-substrings/ */
//Given a string s, return the number of palindromic substrings in it.
//A string is a palindrome when it reads the same backward as forward.
//A substring is a contiguous sequence of characters within the string.
// 
//Example 1:
//Input: s = "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
//Example 2:
//Input: s = "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    let count = 0;
    for (let i = 0; i < s.length; i++) {
        count += helper(s, i, i);
        count += helper(s, i, i + 1);
    }
    return count;
};
var helper = function(s, start, end) {
    let count = 0;
    while (start >= 0 && end < s.length && s[start] === s[end]) {
        count++;
        start--;
        end++;
    }
    return count;
};