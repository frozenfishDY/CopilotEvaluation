/**https://leetcode.com/problems/number-of-ways-to-select-buildings/ */
//You are given a 0-indexed binary string s which represents the types of buildings along a street where:
//	s[i] = '0' denotes that the ith building is an office and
//	s[i] = '1' denotes that the ith building is a restaurant.
//As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.
//	For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
//Return the number of valid ways to select 3 buildings.
// 
//Example 1:
//Input: s = "001101"
//Output: 6
//Explanation: 
//The following sets of indices selected are valid:
//- [0,2,4] from "001101" forms "010"
//- [0,3,4] from "001101" forms "010"
//- [1,2,4] from "001101" forms "010"
//- [1,3,4] from "001101" forms "010"
//- [2,4,5] from "001101" forms "101"
//- [3,4,5] from "001101" forms "101"
//No other selection is valid. Thus, there are 6 total ways.
//Example 2:
//Input: s = "11100"
//Output: 0
//Explanation: It can be shown that there are no valid selections.
// 
//Constraints:
//	3 <= s.length <= 105
//	s[i] is either '0' or '1'.
/**
 * @param {string} s
 * @return {number}
 */
var numberOfWays = function(s) {
    let n = s.length;
    let mod = 1e9 + 7;
    let dp = new Array(n + 1).fill(0);
    let count = 0;
    for (let i = 0; i < n; i++) {
        if (s[i] === '1') {
            count++;
        }
    }
    if (count < 3) {
        return 0;
    }
    dp[3] = count * (count - 1) * (count - 2) / 6;
    for (let i = 4; i <= n; i++) {
        if (s[i - 1] === '1') {
            count--;
        }
        dp[i] = dp[i - 1] + (count * (count - 1) / 2) % mod;
    }
    return dp[n] % mod;
};