/**https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/ */
//You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.
//A cornered path is defined as a set of adjacent cells with at most one turn. More specifically, the path should exclusively move either horizontally or vertically up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the alternate direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.
//The product of a path is defined as the product of all the values in the path.
//Return the maximum number of trailing zeros in the product of a cornered path found in grid.
//Note:
//Horizontal movement means moving in either the left or right direction.
//Vertical movement means moving in either the up or down direction.


class MaximumTrailingZerosInACorneredPath {
    public int maxTrailingZeros(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dp = new int[m][n][2];
        int[][] directions = new int[][]{{0, 1}, {1, 0}};
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int[] dir : directions){
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if(x < m && y < n){
                        int[] temp = new int[2];
                        temp[0] = dp[x][y][0];
                        temp[1] = dp[x][y][1];
                        if(grid[i][j] == 0){
                            temp[0] = 0;
                            temp[1] = 0;
                        }
                        else{
                            while(grid[i][j] % 2 == 0){
                                temp[0]++;
                                grid[i][j] /= 2;
                            }
                            while(grid[i][j] % 5 == 0){
                                temp[1]++;
                                grid[i][j] /= 5;
                            }
                        }
                        if(temp[0] > dp[i][j][0] || (temp[0] == dp[i][j][0] && temp[1] > dp[i][j][1])){
                            dp[i][j][0] = temp[0];
                            dp[i][j][1] = temp[1];
                        }
                    }
                }
                res = Math.max(res, dp[i][j][1]);
            }
        }
        return res;
        
    }
}
     
    