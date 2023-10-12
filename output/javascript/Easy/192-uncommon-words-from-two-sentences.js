/**https://leetcode.com/problems/uncommon-words-from-two-sentences/ */
//A sentence is a string of single-space separated words where each word consists only of lowercase letters.
//A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
//Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
// 
//Example 1:
//Input: s1 = "this apple is sweet", s2 = "this apple is sour"
//Output: ["sweet","sour"]
//Example 2:
//Input: s1 = "apple apple", s2 = "banana"
//Output: ["banana"]
// 
//Constraints:
//	1 <= s1.length, s2.length <= 200
//	s1 and s2 consist of lowercase English letters and spaces.
//	s1 and s2 do not have leading or trailing spaces.
//	All the words in s1 and s2 are separated by a single space.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function(s1, s2) {
    let arr1 = s1.split(' ');
	let arr2 = s2.split(' ');
	let map = new Map();
	for (let i = 0; i < arr1.length; i++) {
		if (map.has(arr1[i])) {
			map.set(arr1[i], map.get(arr1[i]) + 1);
		} else {
			map.set(arr1[i], 1);
		}
	}
	for (let i = 0; i < arr2.length; i++) {
		if (map.has(arr2[i])) {
			map.set(arr2[i], map.get(arr2[i]) + 1);
		} else {
			map.set(arr2[i], 1);
		}
	}
	let ans = [];
	for (let [key, value] of map.entries()) {
		if (value === 1) ans.push(key);
	}
	return ans;
};