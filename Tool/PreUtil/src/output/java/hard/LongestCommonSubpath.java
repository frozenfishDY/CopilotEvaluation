/**https://leetcode.com/problems/longest-common-subpath/ */
//There is a country of n cities numbered from 0 to n - 1. In this country, there is a road connecting every pair of cities.
//There are m friends numbered from 0 to m - 1 who are traveling through the country. Each one of them will take a path consisting of some cities. Each path is represented by an integer array that contains the visited cities in order. The path may contain a city more than once, but the same city will not be listed consecutively.
//Given an integer n and a 2D integer array paths where paths[i] is an integer array representing the path of the ith friend, return the length of the longest common subpath that is shared by every friend's path, or 0 if there is no common subpath at all.
//A subpath of a path is a contiguous sequence of cities within that path.


class LongestCommonSubpath {
    public int longestCommonSubpath(int n, int[][] paths) {
        int m = paths.length;
        int[][] g = new int[n][n];
        int[] inDegree = new int[n];
        for (int[] path : paths) {
            for (int i = 1; i < path.length; i++) {
                int u = path[i - 1];
                int v = path[i];
                g[u][v] = 1;
                inDegree[v]++;
            }
        }
        int[] queue = new int[n];
        int head = 0;
        int tail = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue[tail++] = i;
            }
        }
        int[] colorCount = new int[m];
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
     
    