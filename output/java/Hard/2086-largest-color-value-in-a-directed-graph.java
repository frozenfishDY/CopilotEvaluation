/**https://leetcode.com/problems/largest-color-value-in-a-directed-graph/ */
//There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
//You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
//A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
//Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.


class LargestColorValueInADirectedGraph {
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        int[][] g = new int[n][n];
        int[] inDegree = new int[n];
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            g[u][v] = 1;
            inDegree[v]++;
        }
        int[] queue = new int[n];
        int head = 0;
        int tail = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue[tail++] = i;
            }
        }
        int[] colorCount = new int[26];
        int[] maxColorCount = new int[n];
        int[] maxColor = new int[n];
        int[] color = new int[n];
        while (head < tail) {
            int u = queue[head++];
            colorCount[color[u]]--;
            for (int v = 0; v < n; v++) {
                if (g[u][v] == 1) {
                    if (color[u] == color[v]) {
                        maxColorCount[v] = Math.max(maxColorCount[v], maxColorCount[u] + 1);
                    } else if (colorCount[color[u]] < colorCount[color[v]]) {
                        maxColorCount[v] = maxColorCount[u] + 1;
                        maxColor[v] = color[v];
                    } else {
                        maxColorCount[v] = maxColorCount[u];
                        maxColor[v] = maxColor[u];
                    }
                    if (--inDegree[v] == 0) {
                        queue[tail++] = v;
                    }
                }
            }
            colorCount[color[u]]++;
        }
        if (tail < n) {
            return -1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, maxColorCount[i] + 1);
        }
        return ans;
        
    }
}
     
    