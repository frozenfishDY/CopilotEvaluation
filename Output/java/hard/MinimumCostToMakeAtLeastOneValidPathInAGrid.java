/**https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/ */
//Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
//1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
//2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
//3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
//4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
//Notice that there could be some signs on the cells of the grid that point outside the grid.
//You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.
//You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
//Return the minimum cost to make the grid have at least one valid path.


class MinimumCostToMakeAtLeastOneValidPathInAGrid {
    public int minCost(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int[][] cost = new int[m][n];
        for(int i = 0; i < m; i++){
            Arrays.fill(cost[i], Integer.MAX_VALUE);
        }
        cost[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.add(new int[]{0, 0, 0});
        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            int x = curr[0];
            int y = curr[1];
            int c = curr[2];
            if(x == m - 1 && y == n - 1) return c;
            for(int i = 0; i < 4; i++){
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int nc = c + (grid[x][y] == i + 1 ? 0 : 1);
                if(nc < cost[nx][ny]){
                    cost[nx][ny] = nc;
                    pq.add(new int[]{nx, ny, nc});
                }
            }
        }
        return -1;
        
    }
}
     
    