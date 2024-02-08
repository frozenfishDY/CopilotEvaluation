/**https://leetcode.com/problems/find-the-substring-with-maximum-cost/ */
//You are given a string s, a string chars of distinct characters and an integer array vals of the same length as chars.
//The cost of the substring is the sum of the values of each character in the substring. The cost of an empty string is considered 0.
//The value of the character is defined in the following way:
//	If the character is not in the string chars, then its value is its corresponding position (1-indexed) in the alphabet.
//	
//		For example, the value of 'a' is 1, the value of 'b' is 2, and so on. The value of 'z' is 26.
//	
//	
//	Otherwise, assuming i is the index where the character occurs in the string chars, then its value is vals[i].
//Return the maximum cost among all substrings of the string s.
// 
//Example 1:
//Input: s = "adaa", chars = "d", vals = [-1000]
//Output: 2
//Explanation: The value of the characters "a" and "d" is 1 and -1000 respectively.
//The substring with the maximum cost is "aa" and its cost is 1 + 1 = 2.
//It can be proven that 2 is the maximum cost.
//Example 2:
//Input: s = "abc", chars = "abc", vals = [-1,-1,-1]
//Output: 0
//Explanation: The value of the characters "a", "b" and "c" is -1, -1, and -1 respectively.
//The substring with the maximum cost is the empty substring "" and its cost is 0.
//It can be proven that 0 is the maximum cost.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consist of lowercase English letters.
//	1 <= chars.length <= 26
//	chars consist of distinct lowercase English letters.
//	vals.length == chars.length
//	-1000 <= vals[i] <= 1000
/**
 * @param {string} s
 * @param {string} chars
 * @param {number[]} vals
 * @return {number}
 */
var maximumCostSubstring = function(s, chars, vals) {
    let n = s.length;
    let max = 0;
    let prev = 0;
    for (let i = 0; i < n; i++) {
        let val = vals[chars.indexOf(s[i])];
        if (val === -1000) {
            prev = 0;
            continue;
        }
        prev = Math.max(prev + val, val);
        max = Math.max(max, prev);
    }
    return max;
};