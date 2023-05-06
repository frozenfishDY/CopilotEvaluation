/**https://leetcode.com/problems/equal-row-and-column-pairs/ */
//Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
//A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).


int equalPairs(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = *gridColSize;
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1){
                dp[i][j] = 1;
                if(i > 0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j > 0){
                    dp[i][j] += dp[i][j-1];
                }
                if(i > 0 && j > 0){
                    dp[i][j] -= dp[i-1][j-1];
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans += dp[i][j];
        }
    }
    return ans;

}

    