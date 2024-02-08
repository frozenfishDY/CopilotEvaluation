/**https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/ */
//There exists an undirected and initially unrooted tree with n nodes indexed from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//Each node has an associated price. You are given an integer array price, where price[i] is the price of the ith node.
//The price sum of a given path is the sum of the prices of all nodes lying on that path.
//The tree can be rooted at any node root of your choice. The incurred cost after choosing root is the difference between the maximum and minimum price sum amongst all paths starting at root.
//Return the maximum possible cost amongst all possible root choices.


class DifferenceBetweenMaximumAndMinimumPriceSum {
    public long maxOutput(int n, int[][] edges, int[] price) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        long[] sum = new long[n];
        long[] count = new long[n];
        dfs(graph, sum, count, 0, -1, price);
        long res = Long.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            res = Math.max(res, sum[i] - sum[0] + sum[0] - count[i] * price[i]);
        }
        return res;
        
        
    }
}
     
    