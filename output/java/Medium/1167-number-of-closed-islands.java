/**https://leetcode.com/problems/number-of-closed-islands/ */
//Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
//Return the number of closed islands.
// 
//Example 1:
//Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
//Output: 2
//Explanation: 
//Islands in gray are closed because they are completely surrounded by water (group of 1s).
//Example 2:
//Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//Output: 1
//Example 3:
//Input: grid = [[1,1,1,1,1,1,1],
//               [1,0,0,0,0,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,1,0,1,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,0,0,0,0,1],
//               [1,1,1,1,1,1,1]]
//Output: 2
// 
//Constraints:
//	1 <= grid.length, grid[0].length <= 100
//	0 <= grid[i][j] <=1
class Solution {
    public int closedIsland(int[][] grid) {
        int ans = 0;
        int[][] dirs = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        for(int i = 1; i < grid.length-1; i++) {
            for(int j = 1; j < grid[0].length-1; j++) {
                if(grid[i][j] == 0 && !visited[i][j]) {
                    boolean isClosed = true;
                    Stack<int[]> stack = new Stack<>();
                    stack.push(new int[]{i, j});
                    visited[i][j] = true;
                    while(!stack.isEmpty()) {
                        int[] cur = stack.pop();
                        for(int[] dir : dirs) {
                            int x = cur[0]+dir[0], y = cur[1]+dir[1];
                            if(x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) {
                                isClosed = false;
                                continue;
                            }
                            if(grid[x][y] == 0 && !visited[x][y]) {
                                stack.push(new int[]{x, y});
                                visited[x][y] = true;
                            }
                        }
                    }
                    if(isClosed) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
}