/**https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/ */
//Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
//Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
//Note that you can return the indices of the edges in any order.


class FindCriticalAndPseudoCriticalEdgesInMinimumSpanningTree {
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        int m = edges.length;
        for(int i = 0; i < m; i++){
            edges[i] = new int[]{edges[i][0], edges[i][1], edges[i][2], i};
        }
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);
        UnionFind uf = new UnionFind(n);
        int value = 0;
        for(int i = 0; i < m; i++){
            if(uf.union(edges[i][0], edges[i][1])){
                value += edges[i][2];
            }
        }
        List<List<Integer>> ans = new ArrayList<>();
        for(int i = 0; i < 2; i++){
            ans.add(new ArrayList<>());
        }
        for(int i = 0; i < m; i++){
            UnionFind uf1 = new UnionFind(n);
            int v = 0;
            for(int j = 0; j < m; j++){
                if(i != j && uf1.union(edges[j][0], edges[j][1])){
                    v += edges[j][2];
                }
            }
            if(uf1.setCount != 1 || (uf1.setCount == 1 && v > value)){
                ans.get(0).add(edges[i][3]);
                continue;
            }
            UnionFind uf2 = new UnionFind(n);
            uf2.union(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for(int j = 0; j < m; j++){
                if(i != j && uf2.union(edges[j][0], edges[j][1])){
                    v += edges[j][2];
                }
            }
            if(v == value){
                ans.get(1).add(edges[i][3]);
            }
        }
        return ans;
        
        
    }
}
     
    