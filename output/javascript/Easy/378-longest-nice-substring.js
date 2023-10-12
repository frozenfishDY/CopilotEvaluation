/**https://leetcode.com/problems/longest-nice-substring/ */
//A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
//Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
// 
//Example 1:
//Input: s = "YazaAay"
//Output: "aAa"
//Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
//"aAa" is the longest nice substring.
//Example 2:
//Input: s = "Bb"
//Output: "Bb"
//Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
//Example 3:
//Input: s = "c"
//Output: ""
//Explanation: There are no nice substrings.
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of uppercase and lowercase English letters.
/**
 * @param {string} s
 * @return {string}
 */
var longestNiceSubstring = function(s) {
    let arr = s.split('');
    let max = '';
    for (let i = 0; i < arr.length; i++) {
        for (let j = i; j < arr.length; j++) {
            let sub = s.slice(i, j + 1);
            if (isNice(sub) && sub.length > max.length) max = sub;
        }
    }
    return max;
};
var isNice = function(s) {
    let map = new Map();
    for (let char of s) {
        if (map.has(char)) map.set(char, map.get(char) + 1);
        else map.set(char, 1);
    }
    for (let char of s) {
        if (map.get(char.toLowerCase()) !== map.get(char.toUpperCase())) return false;
    }
    return true;
};