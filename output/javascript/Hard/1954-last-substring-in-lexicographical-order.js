/**https://leetcode.com/problems/last-substring-in-lexicographical-order/ */
//Given a string s, return the last substring of s in lexicographical order.
// 
//Example 1:
//Input: s = "abab"
//Output: "bab"
//Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
//Example 2:
//Input: s = "leetcode"
//Output: "tcode"
// 
//Constraints:
//	1 <= s.length <= 4 * 105
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var lastSubstring = function(s) {
    let i = 0;
    let j = 1;
    let k = 0;
    let len = s.length;
    while (j + k < len) {
        if (s[i + k] === s[j + k]) {
            k++;
            continue;
        }
        if (s[i + k] < s[j + k]) {
            i = Math.max(i + k + 1, j);
        } else {
            j = Math.max(j + k + 1, i);
        }
        k = 0;
    }
    return s.substring(i);
};