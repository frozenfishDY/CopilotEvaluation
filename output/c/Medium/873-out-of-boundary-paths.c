/**https://leetcode.com/problems/out-of-boundary-paths/ */
//There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
//Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
//Output: 6
//Example 2:
//Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
//Output: 12
// 
//Constraints:
//	1 <= m, n <= 50
//	0 <= maxMove <= 50
//	0 <= startRow < m
//	0 <= startColumn < n
int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
int mod = 1000000007;
	int dp[m][n][maxMove + 1];
	memset(dp, 0, sizeof(dp));
	int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
	for (int i = 0; i < m; i++) {
		dp[i][0][0]++;
		dp[i][n - 1][0]++;
	}
	for (int j = 0; j < n; j++) {
		dp[0][j][0]++;
		dp[m - 1][j][0]++;
	}
	for (int k = 1; k <= maxMove; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n;j++) {
				for (int d = 0; d < 4; d++) {
					int prevRow = i + directions[d][0];
					int prevCol = j + directions[d][1];
					if (prevRow >= 0 && prevRow < m && prevCol >= 0 && prevCol < n) {
						dp[i][j][k] = (dp[i][j][k] + dp[prevRow][prevCol][k - 1]) % mod;
					}
				}
			}
		}
	}
	return dp[startRow][startColumn][maxMove];
}