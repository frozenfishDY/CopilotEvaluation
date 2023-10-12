/**https://leetcode.com/problems/word-pattern/ */
//Given a pattern and a string s, find if s follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
// 
//Example 1:
//Input: pattern = "abba", s = "dog cat cat dog"
//Output: true
//Example 2:
//Input: pattern = "abba", s = "dog cat cat fish"
//Output: false
//Example 3:
//Input: pattern = "aaaa", s = "dog cat cat dog"
//Output: false
// 
//Constraints:
//	1 <= pattern.length <= 300
//	pattern contains only lower-case English letters.
//	1 <= s.length <= 3000
//	s contains only lowercase English letters and spaces ' '.
//	s does not contain any leading or trailing spaces.
//	All the words in s are separated by a single space.
/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    let sArr = s.split(' ');
	let pArr = pattern.split('');
	let map = new Map();
	if (sArr.length !== pArr.length) return false;
	for (let i = 0; i < sArr.length; i++) {
		if (map.has(pArr[i])) {
			if (map.get(pArr[i]) !== sArr[i]) return false;
		} else {
			if (Array.from(map.values()).indexOf(sArr[i]) !== -1) return false;
			map.set(pArr[i], sArr[i]);
		}
	}
	return true;
};