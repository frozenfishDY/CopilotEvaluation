/**https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/ */
//In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
//In one move the snake can:
//Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
//Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).
//Return the minimum number of moves to reach the target.
//If there is no way to reach the target, return -1.


class MinimumMovesToReachTargetWithRotations {
    public int minimumMoves(int[][] grid) {
        int n = grid.length;
        int[][][] visited = new int[n][n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j][0] = Integer.MAX_VALUE;
                visited[i][j][1] = Integer.MAX_VALUE;
            }
        }
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 0, 0});
        visited[0][0][0] = 0;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];
            int dir = cur[2];
            int step = cur[3];
            if (x == n - 1 && y == n - 2 && dir == 0) {
                return step;
            }
            if (dir == 0) {
                if (y + 1 < n && grid[x][y + 1] == 0) {
                    if (step + 1 < visited[x][y + 1][0]) {
                        visited[x][y + 1][0] = step + 1;
                        queue.offer(new int[]{x, y + 1, 0, step + 1});
                    }
                }
                if (x + 1 < n && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0) {
                    if (step + 1 < visited[x + 1][y][1]) {
                        visited[x + 1][y][1] = step + 1;
                        queue.offer(new int[]{x + 1, y, 1, step + 1});
                    }
                }
            } else {
                if (x + 1 < n && grid[x + 1][y] == 0) {
                    if (step + 1 < visited[x + 1][y][1]) {
                        visited[x + 1][y][1] = step + 1;
                        queue.offer(new int[]{x + 1, y, 1, step + 1});
                    }
                }
                if (y + 1 < n && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0) {
                    if (step + 1 < visited[x][y + 1][0]) {
                        visited[x][y + 1][0] = step + 1;
                        queue.offer(new int[]{x, y + 1, 0, step + 1});
                    }
                }

                
        
    }
}
     
    