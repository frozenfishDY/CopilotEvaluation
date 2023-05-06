/**https://leetcode.com/problems/triangle/ */
//Given a triangle array, return the minimum path sum from top to bottom.
//For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int dp[triangleSize][*triangleColSize];
    for(int i = 0; i < triangleSize; i++){
        for(int j = 0; j < *triangleColSize; j++){
            if(i == 0 && j == 0){
                dp[i][j] = triangle[i][j];
            }
            else if(i == 0){
                dp[i][j] = dp[i][j - 1] + triangle[i][j];
            }
            else if(j == 0){
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else{
                dp[i][j] = fmin(dp[i - 1][j], dp[i][j - 1]) + triangle[i][j];
            }
        }
    }
    int min = dp[triangleSize - 1][0];
    for(int i = 1; i < *triangleColSize; i++){
        if(dp[triangleSize - 1][i] < min){
            min = dp[triangleSize - 1][i];
        }
    }
    return min;

}

    