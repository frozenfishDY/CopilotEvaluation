/**https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/ */
//You are given a string s that consists of lower case English letters and brackets.
//Reverse the strings in each pair of matching parentheses, starting from the innermost one.
//Your result should not contain any brackets.
// 
//Example 1:
//Input: s = "(abcd)"
//Output: "dcba"
//Example 2:
//Input: s = "(u(love)i)"
//Output: "iloveu"
//Explanation: The substring "love" is reversed first, then the whole string is reversed.
//Example 3:
//Input: s = "(ed(et(oc))el)"
//Output: "leetcode"
//Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s only contains lower case English characters and parentheses.
//	It is guaranteed that all parentheses are balanced.
/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function(s) {
    var stack = [];
	var str = '';
	for (var i = 0; i < s.length; i++) {
		if (s[i] == '(') {
			stack.push(str);
			str = '';
		} else if (s[i] == ')') {
			str = stack.pop() + str.split('').reverse().join('');
		} else {
			str += s[i];
		}
	}
	return str;
};