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
int numberOfWays(int startPos, int endPos, int k){
int i, j;
	int res = 0;
	int **dp = (int **)malloc(sizeof(int *) * k);
	for (i = 0; i < k; ++i) {
		dp[i] = (int *)malloc(sizeof(int) * 1001);
		memset(dp[i], 0, sizeof(int) * 1001);
	}
	dp[0][startPos] = 1;
	for (i = 1; i < k; ++i) {
		for (j = 0; j < 1001; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000007;
		}
	}
	res = dp[k - 1][endPos];
	for (i = 0; i < k; ++i) {
		free(dp[i]);
	}
	free(dp);
	return res;
}