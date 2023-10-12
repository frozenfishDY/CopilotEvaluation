/**https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/ */
//You are given two positive integers startPos and endPos. Initially, you are standing at position startPos on an infinite number line. With one step, you can move either one position to the left, or one position to the right.
//Given a positive integer k, return the number of different ways to reach the position endPos starting from startPos, such that you perform exactly k steps. Since the answer may be very large, return it modulo 109 + 7.
//Two ways are considered different if the order of the steps made is not exactly the same.
//Note that the number line includes negative integers.
// 
//Example 1:
//Input: startPos = 1, endPos = 2, k = 3
//Output: 3
//Explanation: We can reach position 2 from 1 in exactly 3 steps in three ways:
//- 1 -> 2 -> 3 -> 2.
//- 1 -> 2 -> 1 -> 2.
//- 1 -> 0 -> 1 -> 2.
//It can be proven that no other way is possible, so we return 3.
//Example 2:
//Input: startPos = 2, endPos = 5, k = 10
//Output: 0
//Explanation: It is impossible to reach position 5 from position 2 in exactly 10 steps.
// 
//Constraints:
//	1 <= startPos, endPos, k <= 1000
class Solution {
    public int numberOfWays(int startPos, int endPos, int k) {
        int mod = 1000000007;
        int n = 1001;
        int[][] dp = new int[k + 1][n];
        dp[0][startPos] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < n - 1; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
            }
        }
        return dp[k][endPos];
    }
}