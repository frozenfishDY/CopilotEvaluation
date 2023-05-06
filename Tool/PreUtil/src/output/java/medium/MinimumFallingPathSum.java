/**https://leetcode.com/problems/minimum-falling-path-sum/ */
//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
//A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


class MinimumFallingPathSum {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = dp[i - 1][j] + matrix[i][j];
                if(j > 0){
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
                }
                if(j < n - 1){
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            res = Math.min(res, dp[n - 1][i]);
        }
        return res;
        
        
    }
}

    