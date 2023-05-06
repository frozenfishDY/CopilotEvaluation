/**https://leetcode.com/problems/bricks-falling-when-hit/ */
//You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:
//It is directly connected to the top of the grid, or
//At least one other brick in its four adjacent cells is stable.
//You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).
//Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.
//Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.


class BricksFallingWhenHit {
    public int[] hitBricks(int[][] grid, int[][] hits) {
        int m = grid.length;
        int n = grid[0].length;
        int[] result = new int[hits.length];
        for (int i = 0; i < hits.length; i++) {
            int x = hits[i][0];
            int y = hits[i][1];
            if (grid[x][y] == 1) {
                grid[x][y] = 2;
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                dfs(grid, 0, i);
            }
        }
        for (int i = hits.length - 1; i >= 0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];
            if (grid[x][y] == 2) {
                grid[x][y] = 1;
                if (x == 0 || grid[x - 1][y] == 3 || grid[x + 1][y] == 3 || grid[x][y - 1] == 3 || grid[x][y + 1] == 3) {
                    result[i] = dfs(grid, x, y) - 1;
                }
            }
        }
        return result;
        
    }
}
     
    