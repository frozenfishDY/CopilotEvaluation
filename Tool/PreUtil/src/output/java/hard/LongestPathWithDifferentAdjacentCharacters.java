/**https://leetcode.com/problems/longest-path-with-different-adjacent-characters/ */
//You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.
//You are also given a string s of length n, where s[i] is the character assigned to node i.
//Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.


class LongestPathWithDifferentAdjacentCharacters {
    public int longestPath(int[] parent, String s) {
        int n = s.length();
        int[] dp = new int[n];
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && s.charAt(i) != s.charAt(parent[i])) {
                dp[i] = dp[parent[i]] + 1;
            } else {
                dp[i] = 1;
            }
            res = Math.max(res, dp[i]);
        }
        return res;
        
    }
}
     
    