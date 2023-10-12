/**https://leetcode.com/problems/reachable-nodes-with-restrictions/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.
//Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
//Note that node 0 will not be a restricted node.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
//Output: 4
//Explanation: The diagram above shows the tree.
//We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
//Example 2:
//Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
//Output: 3
//Explanation: The diagram above shows the tree.
//We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.
// 
//Constraints:
//	2 <= n <= 105
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	edges represents a valid tree.
//	1 <= restricted.length < n
//	1 <= restricted[i] < n
//	All the values of restricted are unique.
class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        Map<Integer, Map<Integer, Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], k -> new HashMap<>()).put(edge[1], edge[2]);
            graph.computeIfAbsent(edge[1], k -> new HashMap<>()).put(edge[0], edge[2]);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        Map<Integer, Integer> dist = new HashMap<>();
        pq.offer(new int[]{0, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int node = cur[0];
            int d = cur[1];
            if (dist.containsKey(node)) {
                continue;
            }
            dist.put(node, d);
            for (int next : graph.getOrDefault(node, new HashMap<>()).keySet()) {
                if (dist.containsKey(next)) {
                    continue;
                }
                pq.offer(new int[]{next, d + graph.get(node).get(next) + 1});
            }
        }
        int res = 0;
        for (int[] edge : edges) {
            int d1 = dist.getOrDefault(edge[0], 0);
            int d2 = dist.getOrDefault(edge[1], 0);
            if (d1 > d2) {
                res += edge[2];
            } else {
                int left = edge[2] - (d2 - d1);
                res += Math.max(0, left);
            }
        }
        for (int r : restricted) {
            if (dist.containsKey(r)) {
                res++;
            }
        }
        return res;
    }
}