/**https://leetcode.com/problems/redundant-connection-ii/ */
//In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
//The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
//The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.
//Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.


class RedundantConnectionIi {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];
        int[] candA = null;
        int[] candB = null;
        for (int[] edge : edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else {
                candA = new int[]{parent[edge[1]], edge[1]};
                candB = new int[]{edge[0], edge[1]};
                edge[1] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int[] edge : edges) {
            if (edge[1] == 0) {
                continue;
            }
            int rootX = find(parent, edge[0]);
            int rootY = find(parent, edge[1]);
            if (rootX == rootY) {
                if (candA == null) {
                    return edge;
                } else {
                    return candA;
                }
            }
            parent[rootY] = rootX;
        }
        return candB;
        
    }
}
     
    