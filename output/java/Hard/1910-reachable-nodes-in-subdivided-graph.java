/**https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/ */
//You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.
//The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you will not subdivide the edge.
//To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].
//In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.
//Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.


class ReachableNodesInSubdividedGraph {
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        Map<Integer, Map<Integer, Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], x -> new HashMap<>()).put(edge[1], edge[2]);
            graph.computeIfAbsent(edge[1], x -> new HashMap<>()).put(edge[0], edge[2]);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        pq.offer(new int[]{0, maxMoves});
        Map<Integer, Integer> dist = new HashMap<>();
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int u = cur[0], d = cur[1];
            if (dist.containsKey(u)) {
                continue;
            }
            dist.put(u, d);
            for (int v : graph.getOrDefault(u, new HashMap<>()).keySet()) {
                int w = graph.get(u).get(v);
                if (!dist.containsKey(v) && d > w) {
                    pq.offer(new int[]{v, d - w - 1});
                }
            }
        }
        int res = dist.size();
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int du = dist.getOrDefault(u, 0);
            int dv = dist.getOrDefault(v, 0);
            res += Math.min(du + dv, w);
            if (du > w) {
                res -= du - w;
            }
            if (dv > w) {
                res -= dv - w;
            }
        }
        return res;
        
    }
}
     
    