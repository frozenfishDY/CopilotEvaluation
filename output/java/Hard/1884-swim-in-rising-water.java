/**https://leetcode.com/problems/swim-in-rising-water/ */
//You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
//The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
//Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).


class SwimInRisingWater {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int[][] visited = new int[n][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.add(new int[]{grid[0][0],0,0});
        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            int x = curr[1];
            int y = curr[2];
            if(x==n-1 && y==n-1) return curr[0];
            if(visited[x][y]==1) continue;
            visited[x][y]=1;
            for(int[] d:dir){
                int nx = x+d[0];
                int ny = y+d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && visited[nx][ny]==0){
                    pq.add(new int[]{Math.max(curr[0],grid[nx][ny]),nx,ny});
                }
            }
        }
        return -1;
        
    }
}
     
    