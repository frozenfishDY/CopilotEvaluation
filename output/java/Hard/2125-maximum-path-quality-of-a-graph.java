/**https://leetcode.com/problems/maximum-path-quality-of-a-graph/ */
//There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed integer array values where values[i] is the value of the ith node. You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the nodes uj and vj, and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.
//A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds to complete. You may visit the same node multiple times. The quality of a valid path is the sum of the values of the unique nodes visited in the path (each node's value is added at most once to the sum).
//Return the maximum quality of a valid path.
//Note: There are at most four edges connected to each node.


class MaximumPathQualityOfAGraph {
    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        int n = values.length;
        int[][][] dp = new int[n][n][maxTime + 1];
        int[][][] dp2 = new int[n][n][maxTime + 1];
        int[][][] dp3 = new int[n][n][maxTime + 1];
        int[][][] dp4 = new int[n][n][maxTime + 1];
        int[][][] dp5 = new int[n][n][maxTime + 1];
        int[][][] dp6 = new int[n][n][maxTime + 1];
        int[][][] dp7 = new int[n][n][maxTime + 1];
        int[][][] dp8 = new int[n][n][maxTime + 1];
        int[][][] dp9 = new int[n][n][maxTime + 1];
        int[][][] dp10 = new int[n][n][maxTime + 1];
        int[][][] dp11 = new int[n][n][maxTime + 1];
        int[][][] dp12 = new int[n][n][maxTime + 1];
        int[][][] dp13 = new int[n][n][maxTime + 1];
        int[][][] dp14 = new int[n][n][maxTime + 1];
        int[][][] dp15 = new int[n][n][maxTime + 1];
        int[][][] dp16 = new int[n][n][maxTime + 1];
        int[][][] dp17 = new int[n][n][maxTime + 1];
        int[][][] dp18 = new int[n][n][maxTime + 1];
        int[][][] dp19 = new int[n][n][maxTime + 1];
        int[][][] dp20 = new int[n][n][maxTime + 1];
        int[][][] dp21 = new int[n][n][maxTime + 1];
        int[][][] dp22 = new int[n][n][maxTime + 1];
        int[][][] dp23 = new int[n][n][maxTime + 1];
        int[][][] dp24 = new int[n][n][maxTime + 1];
        int[][][] dp25 = new int[n][n][maxTime + 1];
        int[][][] dp26 = new int[n][n][maxTime + 1 ];
        
    }
}
     
    