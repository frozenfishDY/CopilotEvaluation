/**https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/ */
//You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:
//You should build the array arr which has the following properties:
//	arr has exactly n integers.
//	1 <= arr[i] <= m where (0 <= i < n).
//	After applying the mentioned algorithm to arr, the value search_cost is equal to k.
//Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.
// 
//Example 1:
//Input: n = 2, m = 3, k = 1
//Output: 6
//Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
//Example 2:
//Input: n = 5, m = 2, k = 3
//Output: 0
//Explanation: There are no possible arrays that satisify the mentioned conditions.
//Example 3:
//Input: n = 9, m = 1, k = 1
//Output: 1
//Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
// 
//Constraints:
//	1 <= n <= 50
//	1 <= m <= 100
//	0 <= k <= n
int numOfArrays(int n, int m, int k){
int i, j, k, l, m, n;
    int dp[51][51][101];
    int mod = 1000000007;
    for (i = 0; i < 51; i++) {
        for (j = 0; j < 51; j++) {
            for (k = 0; k < 101; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    for (i = 1; i <= m; i++) {
        dp[1][1][i] = 1;
    }
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            for (k = 1; k <= m; k++) {
                dp[i][j][k] = (dp[i][j][k] + (long)dp[i - 1][j][k] * k) % mod;
                for (l = 1; l < k; l++) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][l]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (i = 1; i <= m; i++) {
        ans = (ans + dp[n][k][i]) % mod;
    }
    return ans;
}