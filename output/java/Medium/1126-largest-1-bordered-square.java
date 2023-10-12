/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]_x000D_
//Output: 9_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,1,0,0]]_x000D_
//Output: 1_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= grid.length <= 100_x000D_
//	1 <= grid[0].length <= 100_x000D_
//	grid[i][j] is 0 or 1_x000D_
class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int ans = 0;
        int[][][] dp = new int[grid.length][grid[0].length][2];
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length;j++) {
                if(grid[i][j] == 1) {
                    dp[i][j][0] = j > 0 ? dp[i][j-1][0]+1 : 1;
                    dp[i][j][1] = i > 0 ? dp[i-1][j][1]+1 : 1;
                    int min = Math.min(dp[i][j][0], dp[i][j][1]);
                    while(min > ans) {
                        if(dp[i][j-min+1][1] >= min && dp[i-min+1][j][0] >= min) {
                            ans = min;
                        }
                        min--;
                    }
                }
            }
        }
        return ans*ans;
    }
}