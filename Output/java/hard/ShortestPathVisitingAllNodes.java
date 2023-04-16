/**https://leetcode.com/problems/shortest-path-visiting-all-nodes/ */
//You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
//Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.


class ShortestPathVisitingAllNodes {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[n][1 << n];
        for (int i = 0; i < n; i++) {
            queue.offer(new int[]{i, 1 << i, 0});
            visited[i][1 << i] = true;
        }
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int u = cur[0], mask = cur[1], dist = cur[2];
            if (mask == (1 << n) - 1) {
                return dist;
            }
            for (int v : graph[u]) {
                int maskV = mask | (1 << v);
                if (!visited[v][maskV]) {
                    queue.offer(new int[]{v, maskV, dist + 1});
                    visited[v][maskV] = true;
                }
            }
        }
        return -1;
        
    }
}
     
    