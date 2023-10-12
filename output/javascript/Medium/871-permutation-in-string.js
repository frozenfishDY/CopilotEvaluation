/**https://leetcode.com/problems/permutation-in-string/ */
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.
// 
//Example 1:
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//Input: s1 = "ab", s2 = "eidboaoo"
//Output: false
// 
//Constraints:
//	1 <= s1.length, s2.length <= 104
//	s1 and s2 consist of lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    let map = new Map();
    for (let char of s1) {
        if (map.has(char)) {
            map.set(char, map.get(char) + 1);
        } else {
            map.set(char, 1);
        }
    }
    let start = 0;
    let end = 0;
    let count = map.size;
    while (end < s2.length) {
        let char = s2[end];
        if (map.has(char)) {
            map.set(char, map.get(char) - 1);
            if (map.get(char) === 0) {
                count--;
            }
        }
        end++;
        while (count === 0) {
            let char = s2[start];
            if (map.has(char)) {
                map.set(char, map.get(char) + 1);
                if (map.get(char) > 0) {
                    count++;
                }
            }
            if (end - start === s1.length) {
                return true;
            }
            start++;
        }
    }
    return false;
};