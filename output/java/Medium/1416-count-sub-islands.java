/**https://leetcode.com/problems/count-sub-islands/ */
//You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
//An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
//Return the number of islands in grid2 that are considered sub-islands.
// 
//Example 1:
//Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
//Output: 3
//Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
//The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
//Example 2:
//Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
//Output: 2 
//Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
//The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
// 
//Constraints:
//	m == grid1.length == grid2.length
//	n == grid1[i].length == grid2[i].length
//	1 <= m, n <= 500
//	grid1[i][j] and grid2[i][j] are either 0 or 1.
class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int m = grid1.length, n = grid1[0].length;
        int res = 0;
        boolean[][] visited = new boolean[m][n];
        int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            Arrays.fill(visited[i], false);
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid2[i][j] == 1) {
                    visited[i][j] = true;
                    if (grid1[i][j] == 1) {
                        q.offer(new int[]{i, j});
                        while (!q.isEmpty()) {
                            int[] cur = q.poll();
                            for (int[] dir : dirs) {
                                int x = cur[0] + dir[0];
                                int y = cur[1] + dir[1];
                                if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1 && !visited[x][y]) {
                                    visited[x][y] = true;
                                    if (grid1[x][y] == 1) {
                                        q.offer(new int[]{x, y});
                                    }
                                }
                            }
                        }
                        res++;
                    }
                }
            }
        }
        return res;
    }
}