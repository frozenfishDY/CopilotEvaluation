/**https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/ */
//You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.
//You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.
//Divide the nodes of the graph into m groups (1-indexed) such that:
//Each node in the graph belongs to exactly one group.
//For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
//Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.


class DivideNodesIntoTheMaximumNumberOfGroups {
    public int magnificentSets(int n, int[][] edges) {
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
        int[] dp = new int[1 << n];
        for (int i = 0; i < n; i++) {
            dp[1 << i] = degree[i];
        }
        for (int i = 1; i < (1 << n); i++) {
            int j = i & (-i);
            int k = i ^ j;
            dp[i] = dp[k] + dp[j];
        }
        int[] ans = new int[n + 1];
        for (int i = 1; i < (1 << n); i++) {
            int j = i & (-i);
            int k = i ^ j;
            if (dp[i] % 2 == 0) {
                ans[dp[i] / 2] = Math.max(ans[dp[i] / 2], ans[dp[k] / 2] + ans[dp[j] / 2] + 1);
            }
        }
        return ans[n / 2];
        
    }
}
     
    