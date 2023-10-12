/**https://leetcode.com/problems/as-far-from-land-as-possible/ */
//Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
//The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
// 
//Example 1:
//Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
//Output: 2
//Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
//Example 2:
//Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
//Output: 4
//Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
class Solution {
    public int maxDistance(int[][] grid) {
        int n = grid.length;
        int[][] dist = new int[n][n];
        Queue<int[]> queue = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            Arrays.fill(dist[i], -1);
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    queue.add(new int[]{i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int ans = -1;
        while(!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1], d = dist[x][y];
            ans = Math.max(ans, d);
            if(x > 0 && dist[x-1][y] == -1) {
                dist[x-1][y] = d+1;
                queue.add(new int[]{x-1, y});
            }
            if(x < n-1 && dist[x+1][y] == -1) {
                dist[x+1][y] = d+1;
                queue.add(new int[]{x+1, y});
            }
            if(y > 0 && dist[x][y-1] == -1) {
                dist[x][y-1] = d+1;
                queue.add(new int[]{x, y-1});
            }
            if(y < n-1 && dist[x][y+1] == -1) {
                dist[x][y+1] = d+1;
                queue.add(new int[]{x, y+1});
            }
        }
        return ans == 0 ? -1 : ans;
    }
}