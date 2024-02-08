/**https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ */
//A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
//The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
//Your task is to move the box 'B' to the target position 'T' under the following rules:
//The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
//The character '.' represents the floor which means a free cell to walk.
//The character '#' represents the wall which means an obstacle (impossible to walk there).
//There is only one box 'B' and one target cell 'T' in the grid.
//The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
//The player cannot walk through the box.
//Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.


class MinimumMovesToMoveABoxToTheirTargetLocation {
    public int minPushBox(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][][] visited = new int[m][n][4];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(visited[i][j], Integer.MAX_VALUE);
            }
        }
        int[] box = new int[2];
        int[] target = new int[2];
        int[] player = new int[2];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') {
                    box[0] = i;
                    box[1] = j;
                } else if (grid[i][j] == 'T') {
                    target[0] = i;
                    target[1] = j;
                } else if (grid[i][j] == 'S') {
                    player[0] = i;
                    player[1] = j;
                }
            }
        }
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{box[0], box[1], player[0], player[1], 0});
        visited[box[0]][box[1]][getDir(player, box)] = 0;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int bx = cur[0];
            int by = cur[1];
            int px = cur[2];
            int py = cur[3];
            int step = cur[4];
            if (bx == target[0] && by == target[1]) {
                return step;
            }
            for (int[] dir : new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                int nx = bx + dir[0];
                int ny = by + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') {
                    continue;
                }
                int npx = bx - dir[0];
                int npy = by - dir[1];
                if (npx == px && npy == py)
                    if (visited[nx][ny][getDir(new int[]{npx, npy}, new int[]{nx, ny})] > step) {
                        visited[nx][ny][getDir(new int[]{npx, npy}, new int[]{nx, ny})] = step;
                        queue.offer(new int[]{nx, ny, npx, npy, step});
                    }

                    
        
    }
}
     
    