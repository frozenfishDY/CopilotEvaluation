/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
/**
 * @param {string} s
 * @return {string}
 */
var smallestSubsequence = function(s) {
    const stack = [];
    const map = new Map();
    for (let c of s) {
        map.set(c, map.get(c) + 1 || 1);
    }
    for (let c of s) {
        map.set(c, map.get(c) - 1);
        if (stack.includes(c)) {
            continue;
        }
        while (stack.length && c < stack[stack.length - 1] && map.get(stack[stack.length - 1]) > 0) {
            stack.pop();
        }
        stack.push(c);
    }
    return stack.join('');
};