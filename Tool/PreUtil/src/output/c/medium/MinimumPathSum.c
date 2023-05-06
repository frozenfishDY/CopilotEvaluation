/**https://leetcode.com/problems/minimum-path-sum/ */
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time.


int minPathSum(int** grid, int gridSize, int* gridColSize){
    int dp[gridSize][*gridColSize];
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }
            else if(i == 0){
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
            else if(j == 0){
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else{
                dp[i][j] = fmin(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }
    return dp[gridSize - 1][*gridColSize - 1];

}

    