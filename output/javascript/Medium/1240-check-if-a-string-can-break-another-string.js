/**https://leetcode.com/problems/check-if-a-string-can-break-another-string/ */
//Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.
//A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
// 
//Example 1:
//Input: s1 = "abc", s2 = "xya"
//Output: true
//Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
//Example 2:
//Input: s1 = "abe", s2 = "acd"
//Output: false 
//Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
//Example 3:
//Input: s1 = "leetcodee", s2 = "interview"
//Output: true
// 
//Constraints:
//	s1.length == n
//	s2.length == n
//	1 <= n <= 10^5
//	All strings consist of lowercase English letters.
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkIfCanBreak = function(s1, s2) {
    const memo1 = {};
    const memo2 = {};
    for (let i = 0; i < s1.length; i++) {
        if (!memo1[s1[i]]) {
            memo1[s1[i]] = 0;
        }
        memo1[s1[i]]++;
        if (!memo2[s2[i]]) {
            memo2[s2[i]] = 0;
        }
        memo2[s2[i]]++;
    }
    const s1Arr = Object.entries(memo1).sort((a,b) => a[0] < b[0] ? -1 : 1);
    const s2Arr = Object.entries(memo2).sort((a,b) => a[0] < b[0] ? -1 : 1);
    let s1Count = 0;
    let s2Count = 0;
    for (let i = 0; i < s1Arr.length; i++) {
        s1Count += s1Arr[i][1];
        s2Count += s2Arr[i][1];
        if (s1Count < s2Count || s2Count < s1Count) {
            return false;
        }
    }
    return true;
};