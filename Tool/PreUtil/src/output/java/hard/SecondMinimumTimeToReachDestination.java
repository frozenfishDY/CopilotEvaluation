/**https://leetcode.com/problems/second-minimum-time-to-reach-destination/ */
//A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.
//Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.
//The second minimum value is defined as the smallest value strictly larger than the minimum value.
//For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
//Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.


class SecondMinimumTimeToReachDestination {
    public int secondMinimum(int n, int[][] edges, int time, int change) {
        int[][] g = new int[n][n];
        for (int[] edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            g[u][v] = g[v][u] = 1;
        }
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;
        int[] queue = new int[n];
        int head = 0;
        int tail = 0;
        queue[tail++] = 0;
        while (head < tail) {
            int u = queue[head++];
            for (int v = 0; v < n; v++) {
                if (g[u][v] == 1) {
                    int d = dist[u] + time;
                    if (d % (2 * change) >= change) {
                        d += 2 * change - d % (2 * change);
                    }
                    if (d < dist[v]) {
                        dist[v] = d;
                        queue[tail++] = v;
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (dist[i] > dist[n - 1]) {
                ans = Math.min(ans, dist[i]);
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
        
    }
}
     
    