/**https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/ */
//You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
//Return the maximum possible length of s.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: arr = ["un","iq","ue"]
//Output: 4
//Explanation: All the valid concatenations are:
//- ""
//- "un"
//- "iq"
//- "ue"
//- "uniq" ("un" + "iq")
//- "ique" ("iq" + "ue")
//Maximum length is 4.
//Example 2:
//Input: arr = ["cha","r","act","ers"]
//Output: 6
//Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
//Example 3:
//Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
//Output: 26
//Explanation: The only string in arr has all 26 characters.
// 
//Constraints:
//	1 <= arr.length <= 16
//	1 <= arr[i].length <= 26
//	arr[i] contains only lowercase English letters.
/**
 * @param {string[]} arr
 * @return {number}
 */
var maxLength = function(arr) {
    var ans = 0;
	var dfs = function(index, mask, len) {
		if (index == arr.length) {
			ans = Math.max(ans, len);
			return;
		}
		dfs(index + 1, mask, len);
		var newMask = 0;
		var valid = true;
		for (var i = 0; i < arr[index].length; i++) {
			var bit = 1 << (arr[index].charCodeAt(i) - 'a'.charCodeAt(0));
			if ((newMask & bit) != 0) {
				valid = false;
				break;
			}
			newMask |= bit;
		}
		if (valid && (newMask & mask) == 0) {
			dfs(index + 1, newMask | mask, len + arr[index].length);
		}
	};
	dfs(0, 0, 0);
	return ans;
};