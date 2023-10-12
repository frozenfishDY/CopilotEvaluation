/**https://leetcode.com/problems/optimal-partition-of-string/ */
//Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.
//Return the minimum number of substrings in such a partition.
//Note that each character should belong to exactly one substring in a partition.
// 
//Example 1:
//Input: s = "abacaba"
//Output: 4
//Explanation:
//Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
//It can be shown that 4 is the minimum number of substrings needed.
//Example 2:
//Input: s = "ssssss"
//Output: 6
//Explanation:
//The only valid partition is ("s","s","s","s","s","s").
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only English lowercase letters.
/**
 * @param {string} s
 * @return {number}
 */
var partitionString = function(s) {
    let map = new Map();
    for (let c of s) {
        map.set(c, map.get(c) + 1 || 1);
    }
    let arr = [...map.entries()].sort((a, b) => a[0].charCodeAt() - b[0].charCodeAt());
    let res = 0;
    for (let i = 0; i < arr.length; i++) {
        if (i === arr.length - 1) {
            res += arr[i][1];
        } else {
            let diff = arr[i + 1][0].charCodeAt() - arr[i][0].charCodeAt();
            if (diff <= k) {
                res += arr[i][1];
            } else {
                res += arr[i][1] - 1;
            }
        }
    }
    return res;
};