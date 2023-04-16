/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.


class MakingALargeIsland {
    public int largestIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int[] size = new int[m * n + 2];
        int index = 2;
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    size[index] = dfs(grid, i, j, index, dirs);
                    max = Math.max(max, size[index]);
                    index++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Set<Integer> set = new HashSet<>();
                    for (int[] dir : dirs) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 1) {
                            set.add(grid[x][y]);
                        }
                    }
                    int sum = 1;
                    for (int num : set) {
                        sum += size[num];
                    }
                    max = Math.max(max, sum);
                }
            }
        }
        return max;
        
        
    }
}
     
    