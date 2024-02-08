/**https://leetcode.com/problems/sum-of-beauty-of-all-substrings/ */
//The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
//	For example, the beauty of "abaacc" is 3 - 1 = 2.
//Given a string s, return the sum of beauty of all of its substrings.
// 
//Example 1:
//Input: s = "aabcb"
//Output: 5
//Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
//Example 2:
//Input: s = "aabcbaa"
//Output: 17
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var beautySum = function(s) {
    let res = 0;
    for (let i = 0; i < s.length; i++) {
        let map = {};
        for (let j = i; j < s.length; j++) {
            map[s[j]] = map[s[j]] + 1 || 1;
            let max = 0;
            let min = Infinity;
            for (let key in map) {
                max = Math.max(max, map[key]);
                min = Math.min(min, map[key]);
            }
            res += max - min;
        }
    }
    return res;
};