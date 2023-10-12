/**https://leetcode.com/problems/swap-for-longest-repeated-character-substring/ */
//You are given a string text. You can swap two of the characters in the text.
//Return the length of the longest substring with repeated characters.
// 
//Example 1:
//Input: text = "ababa"
//Output: 3
//Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
//Example 2:
//Input: text = "aaabaaa"
//Output: 6
//Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
//Example 3:
//Input: text = "aaaaa"
//Output: 5
//Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
// 
//Constraints:
//	1 <= text.length <= 2 * 104
//	text consist of lowercase English characters only.
/**
 * @param {string} text
 * @return {number}
 */
var maxRepOpt1 = function(text) {
    var map = {};
	var ans = 0;
	for (var i = 0; i < text.length; i++) {
		if (map[text[i]] == null) {
			map[text[i]] = [];
		}
		map[text[i]].push(i);
	}
	for (var key in map) {
		var arr = map[key];
		var count = 1;
		var maxCount = 0;
		for (var i = 1; i < arr.length; i++) {
			if (arr[i] == arr[i - 1] + 1) {
				count++;
			} else {
				maxCount = Math.max(maxCount, count);
				count = 1;
				if (arr[i] == arr[i - 1] + 2) {
					count++;
				}
			}
		}
		maxCount = Math.max(maxCount, count);
		ans = Math.max(ans, maxCount + (arr.length > maxCount ? 1 : 0));
	}
	return ans;
};