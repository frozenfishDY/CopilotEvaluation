/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.


class ShortestBridge {
    public int shortestBridge(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        boolean found = false;
        Queue<int[]> q = new LinkedList<>();
        for(int i = 0; i < n; i++){
            if(found){
                break;
            }
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, q);
                    found = true;
                    break;
                }
            }
        }
        int res = 0;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int[] cur = q.poll();
                for(int[] dir : dirs){
                    int x = cur[0] + dir[0];
                    int y = cur[1] + dir[1];
                    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 2){
                        continue;
                    }
                    if(grid[x][y] == 1){
                        return res;
                    }
                    grid[x][y] = 2;
                    q.offer(new int[]{x, y});
                }
            }
            res++;
        }
        return res;
        
        
    }
}

    