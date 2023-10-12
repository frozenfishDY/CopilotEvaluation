/**https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/ */
//You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
//Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 12
//Explanation: There are 12 possible way to paint the grid as shown.
//Example 2:
//Input: n = 5000
//Output: 30228214
// 
//Constraints:
//	n == grid.length
//	1 <= n <= 5000
int numOfWays(int n){
int i, j, k, l, m, n;
    int mod = 1000000007;
    int dp[5001][3][3][3];
    for (i = 0; i < 5001; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                if (i != j && j != k) {
                    dp[1][i][j][k] = 1;
                }
            }
        }
    }
    for (i = 2; i <= n; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    for (m = 0; m < 3; m++) {
                        if (j != k && k != l && l != m) {
                            dp[i][k][l][m] = (dp[i][k][l][m] + dp[i - 1][j][k][l]) % mod;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                ans = (ans + dp[n][i][j][k]) % mod;
            }
        }
    }
    return ans;
}