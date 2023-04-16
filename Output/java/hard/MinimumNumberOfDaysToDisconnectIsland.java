/**https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/ */
//You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
//The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
//In one day, we are allowed to change any single land cell (1) into a water cell (0).
//Return the minimum number of days to disconnect the grid.


class MinimumNumberOfDaysToDisconnectIsland {
    public int minDays(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int[][] prefix = new int[m + 1][n + 1];
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        if(count == 0){
            return 0;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int newCount = 0;
                    for(int k = 0; k < m; k++){
                        for(int l = 0; l < n; l++){
                            if(grid[k][l] == 1){
                                newCount++;
                            }
                        }
                    }
                    if(newCount == 0){
                        return 1;
                    }
                    for(int k = 0; k < m; k++){
                        for(int l = 0; l < n; l++){
                            if(grid[k][l] == 1){
                                boolean flag = false;
                                for(int[] dir : dirs){
                                    int x = k + dir[0];
                                    int y = l + dir[1];
                                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                                        flag = true;
                                        break;
                                    }
                                }
                                if(!flag){
                                    int sum = prefix[k + 1][l + 1] - prefix[k + 1][l] - prefix[k][l + 1] + prefix[k][l];
                                    if(sum == 1){
        
    }
}
     
    