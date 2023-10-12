/**https://leetcode.com/problems/mice-and-cheese/ */
//There are two mice and n different types of cheese, each type of cheese should be eaten by exactly one mouse.
//A point of the cheese with index i (0-indexed) is:
//	reward1[i] if the first mouse eats it.
//	reward2[i] if the second mouse eats it.
//You are given a positive integer array reward1, a positive integer array reward2, and a non-negative integer k.
//Return the maximum points the mice can achieve if the first mouse eats exactly k types of cheese.
// 
//Example 1:
//Input: reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
//Output: 15
//Explanation: In this example, the first mouse eats the 2nd (0-indexed) and the 3rd types of cheese, and the second mouse eats the 0th and the 1st types of cheese.
//The total points are 4 + 4 + 3 + 4 = 15.
//It can be proven that 15 is the maximum total points that the mice can achieve.
//Example 2:
//Input: reward1 = [1,1], reward2 = [1,1], k = 2
//Output: 2
//Explanation: In this example, the first mouse eats the 0th (0-indexed) and 1st types of cheese, and the second mouse does not eat any cheese.
//The total points are 1 + 1 = 2.
//It can be proven that 2 is the maximum total points that the mice can achieve.
// 
//Constraints:
//	1 <= n == reward1.length == reward2.length <= 105
//	1 <= reward1[i], reward2[i] <= 1000
//	0 <= k <= n
/**
 * @param {number[]} reward1
 * @param {number[]} reward2
 * @param {number} k
 * @return {number}
 */
var miceAndCheese = function(reward1, reward2, k) {
    let n = reward1.length;
    let arr = new Array(n);
    for (let i = 0; i < n; i++) {
        arr[i] = [reward1[i], reward2[i]];
    }
    arr.sort((a, b) => b[0]-a[0]);
    let dp = new Array(n+1).fill(0).map(() => new Array(k+1).fill(0));
    for (let i = 1; i <= n; i++) {
        let [val1, val2] = arr[i-1];
        for (let j = 1; j <= k; j++) {
            dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-1]+val1, dp[i-1][j-1]+val2);
        }
    }
    return dp[n][k];
};