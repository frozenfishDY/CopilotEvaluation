/**https://leetcode.com/problems/smallest-string-with-swaps/ */
//You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
//You can swap the characters at any pair of indices in the given pairs any number of times.
//Return the lexicographically smallest string that s can be changed to after using the swaps.
// 
//Example 1:
//Input: s = "dcab", pairs = [[0,3],[1,2]]
//Output: "bacd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[1] and s[2], s = "bacd"
//Example 2:
//Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//Output: "abcd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[0] and s[2], s = "acbd"
//Swap s[1] and s[2], s = "abcd"
//Example 3:
//Input: s = "cba", pairs = [[0,1],[1,2]]
//Output: "abc"
//Explaination: 
//Swap s[0] and s[1], s = "bca"
//Swap s[1] and s[2], s = "bac"
//Swap s[0] and s[1], s = "abc"
// 
//Constraints:
//	1 <= s.length <= 10^5
//	0 <= pairs.length <= 10^5
//	0 <= pairs[i][0], pairs[i][1] < s.length
//	s only contains lower case English letters.
/**
 * @param {string} s
 * @param {number[][]} pairs
 * @return {string}
 */
var smallestStringWithSwaps = function(s, pairs) {
    var n = s.length;
	var fa = [];
	for (var i = 0; i < n; i++) {
		fa[i] = i;
	}
	var find = function(x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	var merge = function(x, y) {
		fa[find(x)] = find(y);
	}
	for (var i = 0; i < pairs.length; i++) {
		merge(pairs[i][0], pairs[i][1]);
	}
	var map = {};
	for (var i = 0; i < n; i++) {
		var root = find(i);
		if (map[root] == null) {
			map[root] = [];
		}
		map[root].push(i);
	}
	var ans = s.split("");
	for (var key in map) {
		var arr = map[key];
		var list = [];
		for (var i = 0; i < arr.length; i++) {
			list.push(s[arr[i]]);
		}
		list.sort();
		for (var i = 0; i < arr.length; i++) {
			ans[arr[i]] = list[i];
		}
	}
	return ans.join("");
};