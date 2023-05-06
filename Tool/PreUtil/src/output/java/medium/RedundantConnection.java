/**https://leetcode.com/problems/redundant-connection/ */
//In this problem, a tree is an undirected graph that is connected and has no cycles.
//You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
//Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.


class RedundantConnection {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            int pu = find(u, parent);
            int pv = find(v, parent);
            if(pu == pv){
                return edge;
            }else{
                parent[pu] = pv;
            }
        }
        return new int[0];
        
        
    }
}

    