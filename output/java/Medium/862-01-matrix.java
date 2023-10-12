/**https://leetcode.com/problems/01-matrix/ */
//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two adjacent cells is 1.
// 
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] result = new int[m][n];
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            if (mat[i][0] == 0) {
                queue.offer(new int[]{i, 0});
                visited[i][0] = true;
                result[i][0] = 0;
            }
            if (mat[i][n - 1] == 0) {
                queue.offer(new int[]{i, n - 1});
                visited[i][n - 1] = true;
                result[i][n - 1] = 0;
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (mat[0][j] == 0) {
                queue.offer(new int[]{0, j});
                visited[0][j] = true;
                result[0][j] = 0;
            }
            if (mat[m - 1][j] == 0) {
                queue.offer(new int[]{m - 1, j});
                visited[m - 1][j] = true;
                result[m - 1][j] = 0;
            }
        }
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int[] dir : dirs) {
                int x = cur[0] + dir[0];
                int y = cur[1] + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    queue.offer(new int[]{x, y});
                    visited[x][y] = true;
                    result[x][y] = result[cur[0]][cur[1]] + 1;
                }
            }
        }
        return result;
    }
}