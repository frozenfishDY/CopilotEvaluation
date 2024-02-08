/**https://leetcode.com/problems/minimum-score-triangulation-of-polygon/ */
//You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).
//You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.
//Return the smallest possible total score that you can achieve with some triangulation of the polygon.


class MinimumScoreTriangulationOfPolygon {
    public int minScoreTriangulation(int[] values) {
        int n = values.length;
        int[][] dp = new int[n][n];
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 2; j < n; j++){
                dp[i][j] = Integer.MAX_VALUE;
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][n - 1];
        
        
    }
}

    