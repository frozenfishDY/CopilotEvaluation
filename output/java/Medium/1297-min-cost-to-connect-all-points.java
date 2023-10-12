/**https://leetcode.com/problems/min-cost-to-connect-all-points/ */
//You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
// 
//Example 1:
//Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//Output: 20
//Explanation: 
//We can connect the points as shown above to get the minimum cost of 20.
//Notice that there is a unique path between every pair of points.
//Example 2:
//Input: points = [[3,12],[-2,5],[-4,1]]
//Output: 18
// 
//Constraints:
//	1 <= points.length <= 1000
//	-106 <= xi, yi <= 106
//	All pairs (xi, yi) are distinct.
class Solution {
    public int minCostConnectPoints(int[][] points) {
        int res = 0, n = points.length;
        int[] dist = new int[n];
        boolean[] visited = new boolean[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;
        for(int i = 0; i < n; i++){
            int cur = -1;
            for(int j = 0; j < n; j++){
                if(!visited[j] && (cur == -1 || dist[j] < dist[cur])){
                    cur = j;
                }
            }
            res += dist[cur];
            visited[cur] = true;
            for(int j = 0; j < n; j++){
                if(!visited[j]){
                    dist[j] = Math.min(dist[j], Math.abs(points[cur][0] - points[j][0]) + Math.abs(points[cur][1] - points[j][1]));
                }
            }
        }
        return res;
    }
}