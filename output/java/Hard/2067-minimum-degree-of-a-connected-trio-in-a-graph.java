/**https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/ */
//You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
//A connected trio is a set of three nodes where there is an edge between every pair of them.
//The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
//Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.


class MinimumDegreeOfAConnectedTrioInAGraph {
    public int minTrioDegree(int n, int[][] edges) {
        int[] degree = new int[n + 1];
        boolean[][] graph = new boolean[n + 1][n + 1];
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            degree[u]++;
            degree[v]++;
            graph[u][v] = true;
            graph[v][u] = true;
        }
        int res = Integer.MAX_VALUE;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(graph[i][j]){
                    for(int k = j + 1; k <= n; k++){
                        if(graph[i][k] && graph[j][k]){
                            res = Math.min(res, degree[i] + degree[j] + degree[k] - 6);
                        }
                    }
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
        
    }
}
     
    