/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var reorganizeString = function(s) {
    const map = new Map();
    for (let c of s) {
        map.set(c, map.get(c) + 1 || 1);
    }
    const sorted = [...map.entries()].sort((a, b) => b[1] - a[1]);
    const max = sorted[0][1];
    if (max > (s.length + 1) / 2) {
        return '';
    }
    const result = new Array(s.length);
    let index = 0;
    for (let [c, count] of sorted) {
        for (let i = 0; i < count; i++) {
            if (index >= s.length) {
                index = 1;
            }
            result[index] = c;
            index += 2;
        }
    }
    return result.join('');
};