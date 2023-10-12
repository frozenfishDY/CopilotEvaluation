/**https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/ */
//You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.
//You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti.
//Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.
//Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.
//A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.
// 
//Example 1:
//Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
//Output: 9
//Explanation:
//The above figure represents the input graph.
//The blue edges represent one of the subgraphs that yield the optimal answer.
//Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal answer. It is not possible to get a subgraph with less weight satisfying all the constraints.
//Example 2:
//Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
//Output: -1
//Explanation:
//The above figure represents the input graph.
//It can be seen that there does not exist any path from node 1 to node 2, hence there are no subgraphs satisfying all the constraints.
// 
//Constraints:
//	3 <= n <= 105
//	0 <= edges.length <= 105
//	edges[i].length == 3
//	0 <= fromi, toi, src1, src2, dest <= n - 1
//	fromi != toi
//	src1, src2, and dest are pairwise distinct.
//	1 <= weight[i] <= 105
class Solution {
    public long minimumWeight(int n, int[][] edges, int src1, int src2, int dest) {
        List<int[]>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[from].add(new int[]{to, weight});
        }
        long[] dist1 = new long[n];
        long[] dist2 = new long[n];
        Arrays.fill(dist1, Long.MAX_VALUE / 2);
        Arrays.fill(dist2, Long.MAX_VALUE / 2);
        dist1[src1] = 0;
        dist2[src2] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{src1, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int from = cur[0];
            long weight = cur[1];
            if (dist1[from] < weight) {
                continue;
            }
            for (int[] next : graph[from]) {
                int to = next[0];
                long nextWeight = next[1];
                if (dist1[to] > dist1[from] + nextWeight) {
                    dist1[to] = dist1[from] + nextWeight;
                    pq.offer(new int[]{to, (int) dist1[to]});
                }
            }
        }
        pq.clear();
        pq.offer(new int[]{src2, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int from = cur[0];
            long weight = cur[1];
            if (dist2[from] < weight) {
                continue;
            }
            for (int[] next : graph[from]) {
                int to = next[0];
                long nextWeight = next[1];
                if (dist2[to] > dist2[from] + nextWeight) {
                    dist2[to] = dist2[from] + nextWeight;
                    pq.offer(new int[]{to, (int) dist2[to]});
                }
            }
        }
        long res = Long.MAX_VALUE;
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
    }
}