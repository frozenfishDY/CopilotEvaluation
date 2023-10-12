/**https://leetcode.com/problems/replace-the-substring-for-balanced-string/ */
//You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
//A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
//Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
// 
//Example 1:
//Input: s = "QWER"
//Output: 0
//Explanation: s is already balanced.
//Example 2:
//Input: s = "QQWE"
//Output: 1
//Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
//Example 3:
//Input: s = "QQQW"
//Output: 2
//Explanation: We can replace the first "QQ" to "ER". 
// 
//Constraints:
//	n == s.length
//	4 <= n <= 105
//	n is a multiple of 4.
//	s contains only 'Q', 'W', 'E', and 'R'.
/**
 * @param {string} s
 * @return {number}
 */
var balancedString = function(s) {
    var map = {};
	var len = s.length;
	var count = len / 4;
	var ans = len;
	for (var i = 0; i < len; i++) {
		if (map[s[i]] == null) {
			map[s[i]] = 0;
		}
		map[s[i]]++;
	}
	var left = 0;
	var right = 0;
	while (right < len) {
		map[s[right]]--;
		while (left < len && map.Q <= count && map.W <= count && map.E <= count && map.R <= count) {
			ans = Math.min(ans, right - left + 1);
			map[s[left]]++;
			left++;
		}
		right++;
	}
	return ans;
};