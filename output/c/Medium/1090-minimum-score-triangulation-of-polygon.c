/**https://leetcode.com/problems/minimum-score-triangulation-of-polygon/ */
//You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).
//You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.
//Return the smallest possible total score that you can achieve with some triangulation of the polygon.


int minScoreTriangulation(int* values, int valuesSize){
    int** dp = (int**)malloc(sizeof(int*) * valuesSize);
    for(int i = 0; i < valuesSize; i++){
        dp[i] = (int*)malloc(sizeof(int) * valuesSize);
        memset(dp[i], 0, sizeof(int) * valuesSize);
    }
    for(int i = valuesSize - 1; i >= 0; i--){
        for(int j = i + 2; j < valuesSize; j++){
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++){
                dp[i][j] = fmin(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
            }
        }
    }
    return dp[0][valuesSize - 1];

}

    