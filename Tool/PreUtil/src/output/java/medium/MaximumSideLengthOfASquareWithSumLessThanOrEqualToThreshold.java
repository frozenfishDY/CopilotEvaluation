/**https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ */
//Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.


class MaximumSideLengthOfASquareWithSumLessThanOrEqualToThreshold {
    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] dp = new int[m + 1][n + 1];
        int max = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
                if(i >= max + 1 && j >= max + 1 && dp[i][j] - dp[i - max - 1][j] - dp[i][j - max - 1] + dp[i - max - 1][j - max - 1] <= threshold){
                    max++;
                }
            }
        }
        return max;
        
        
        
    }
}

    