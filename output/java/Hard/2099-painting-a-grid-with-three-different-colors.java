/**https://leetcode.com/problems/painting-a-grid-with-three-different-colors/ */
//You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
//Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.


class PaintingAGridWithThreeDifferentColors {
    public int colorTheGrid(int m, int n) {
        int mod = 1000000007;
        int[][] dp = new int[m][n];
        int[][] next = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = 1;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    if(j != k){
                        next[j][i] = (next[j][i] + dp[k][i - 1]) % mod;
                    }
                }
            }
            for(int j = 0; j < m; j++){
                dp[j][i] = next[j][i];
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            res = (res + dp[i][n - 1]) % mod;
        }
        return res;
        
    }
}
     
    