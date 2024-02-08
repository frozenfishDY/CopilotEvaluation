/**https://leetcode.com/problems/maximum-length-of-pair-chain/ */
//You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
//A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
//Return the length longest chain which can be formed.
//You do not need to use up all the given intervals. You can select pairs in any order.
// 
//Example 1:
//Input: pairs = [[1,2],[2,3],[3,4]]
//Output: 2
//Explanation: The longest chain is [1,2] -> [3,4].
//Example 2:
//Input: pairs = [[1,2],[7,8],[4,5]]
//Output: 3
//Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
// 
//Constraints:
//	n == pairs.length
//	1 <= n <= 1000
//	-1000 <= lefti < righti <= 1000
/**
 * @param {number[][]} pairs
 * @return {number}
 */
var findLongestChain = function(pairs) {
    pairs.sort((a, b) => a[0] - b[0]);
    let dp = new Array(pairs.length).fill(1);
    for (let i = 1; i < pairs.length; i++) {
        for (let j = 0; j < i; j++) {
            if (pairs[i][0] > pairs[j][1]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[pairs.length - 1];
};