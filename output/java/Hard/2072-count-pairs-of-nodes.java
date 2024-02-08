/**https://leetcode.com/problems/count-pairs-of-nodes/ */
//You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges, the edges in the graph, where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.
//Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
//The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
//a < b
//incident(a, b) > queries[j]
//Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
//Note that there can be multiple edges between the same two nodes.


class CountPairsOfNodes {
    public int[] countPairs(int n, int[][] edges, int[] queries) {
        int[] ans = new int[queries.length];
        int[] degree = new int[n];
        int[][] count = new int[n][n];
        for (int[] edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            degree[u]++;
            degree[v]++;
            count[u][v]++;
            count[v][u]++;
        }
        for (int i = 0; i < queries.length; i++) {
            int q = queries[i];
            int total = 0;
            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (degree[j] + degree[k] > q && degree[j] + degree[k] - count[j][k] <= q) {
                        total++;
                    }
                }
            }
            ans[i] = total;
        }
        return ans;
        
    }
}
     
    