/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.


class FindTheShortestSuperstring {
    public String shortestSuperstring(String[] words) {
        int n = words.length;
        int[][] overlap = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    overlap[i][j] = getOverlap(words[i], words[j]);
                }
            }
        }
        int[][] dp = new int[1 << n][n];
        int[][] parent = new int[1 << n][n];
        for (int mask = 0; mask < (1 << n); mask++) {
            Arrays.fill(parent[mask], -1);
            for (int bit = 0; bit < n; bit++) {
                if (((mask >> bit) & 1) > 0) {
                    int pmask = mask ^ (1 << bit);
                    if (pmask == 0) {
                        continue;
                    }
                    for (int i = 0; i < n; i++) {
                        if (((pmask >> i) & 1) > 0) {
                            int val = dp[pmask][i] + overlap[i][bit];
                            if (val > dp[mask][bit]) {
                                dp[mask][bit] = val;
                                parent[mask][bit] = i;
                            }
                        }
                    }
                }
            }
        }
        int[] perm = new int[n];
        int t = (1 << n) - 1;
        int p = 0;
        for (int j = 0; j < n; j++) {
            if (dp[t][j] > dp[t][p]) {
                p = j;
            }
        }
        int idx = n - 1;
        while (t > 0) {
            perm[idx--] = p;
            int temp = parent[t][p];
            t = t ^ (1 << p);
            p = temp;
        }
        StringBuilder sb = new StringBuilder(words[perm[0]]);
        for (int i = 1; i < n; i++) {
            int overlapLen = overlap[perm[i - 1]][perm[i]];
            sb.append(words[perm[i]].substring(overlapLen));
        }
        return sb.toString();
        
        
    }
}
     
    