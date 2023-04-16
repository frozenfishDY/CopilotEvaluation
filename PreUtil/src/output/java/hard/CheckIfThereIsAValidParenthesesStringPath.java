/**https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/ */
//A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
//It is ().
//It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
//It can be written as (A), where A is a valid parentheses string.
//You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
//The path starts from the upper left cell (0, 0).
//The path ends at the bottom-right cell (m - 1, n - 1).
//The path only ever moves down or right.
//The resulting parentheses string formed by the path is valid.
//Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.


class CheckIfThereIsAValidParenthesesStringPath {
    public boolean hasValidPath(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] dirs = new int[][][]{{{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}}, {{1, 0}, {0, 1}}, {{1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}, {{-1, 0}, {0, -1}}};
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        visited[0][0] = true;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];
            if (x == m - 1 && y == n - 1) {
                return true;
            }
            int[][] dir = dirs[grid[x][y] - '1'];
            for (int[] d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                    continue;
                }
                for (int[] d2 : dirs[grid[nx][ny] - '1']) {
                    if (d2[0] == -d[0] && d2[1] == -d[1]) {
                        queue.offer(new int[]{nx, ny});
                        visited[nx][ny] = true;
                        break;
                    }
                }
            }
        }
        return false;
        
    }
}
     
    