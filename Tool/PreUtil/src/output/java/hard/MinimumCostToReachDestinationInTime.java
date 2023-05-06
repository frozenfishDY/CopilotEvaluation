/**https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/ */
//There is a country of n cities numbered from 0 to n - 1 where all the cities are connected by bi-directional roads. The roads are represented as a 2D integer array edges where edges[i] = [xi, yi, timei] denotes a road between cities xi and yi that takes timei minutes to travel. There may be multiple roads of differing travel times connecting the same two cities, but no road connects a city to itself.
//Each time you pass through a city, you must pay a passing fee. This is represented as a 0-indexed integer array passingFees of length n where passingFees[j] is the amount of dollars you must pay when you pass through city j.
//In the beginning, you are at city 0 and want to reach city n - 1 in maxTime minutes or less. The cost of your journey is the summation of passing fees for each city that you passed through at some moment of your journey (including the source and destination cities).
//Given maxTime, edges, and passingFees, return the minimum cost to complete your journey, or -1 if you cannot complete it within maxTime minutes.


class MinimumCostToReachDestinationInTime {
    public int minCost(int maxTime, int[][] edges, int[] passingFees) {
        int n = passingFees.length;
        int[][] g = new int[n][n];
        int[] inDegree = new int[n];
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            g[u][v] = edge[2];
            g[v][u] = edge[2];
            inDegree[u]++;
            inDegree[v]++;
        }
        int[] queue = new int[n];
        int head = 0;
        int tail = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) {
                queue[tail++] = i;
            }
        }
        int[] colorCount = new int[n];
        int[] maxColorCount = new int[n];
        int[] maxColor = new int[n];
        int[] color = new int[n];
        while (head < tail) {
            int u = queue[head++];
            colorCount[color[u]]--;
            for (int v = 0; v < n; v++) {
                if (g[u][v] > 0) {
                    if (color[u] == color[v]) {
                        maxColorCount[v] = Math.max(maxColorCount[v], maxColorCount[u] + g[u][v]);
                    } else if (colorCount[color[u]] < colorCount[color[v]]) {
                        maxColorCount[v] = maxColorCount[u] + g[u][v];
                        maxColor[v] = color[v];
                    } else {
                        maxColorCount[v] = maxColorCount[u];
                        maxColor[v] = maxColor[u];
                    }
                    if (--inDegree[v] == 1) {
                        queue[tail++] = v;
                    }
                }
            }
            colorCount[color[u]]++;
        }
        if (tail < n) {
            return -1;
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (maxColorCount[i] <= maxTime) {
                ans = Math.min(ans, passingFees[i] + passingFees[maxColor[i]]);
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
        
    }
}
     
    