/**https://leetcode.com/problems/cycle-length-queries-in-a-tree/ */
//You are given an integer n. There is a complete binary tree with 2^(n - 1) nodes. The root of that tree is the node with the value 1, and every node with a value val in the range [1, 2n - 1 - 1] has two children where:
//The left node has the value 2 * val, and
//The right node has the value 2 * val + 1.
//You are also given a 2D integer array queries of length m, where queries[i] = [ai, bi]. For each query, solve the following problem:
//Add an edge between the nodes with values ai and bi.
//Find the length of the cycle in the graph.
//Remove the added edge between nodes with values ai and bi.
//Note that:
//A cycle is a path that starts and ends at the same node, and each edge in the path is visited only once.
//The length of a cycle is the number of edges visited in the cycle.
//There could be multiple edges between two nodes in the tree after adding the edge of the query.
//Return an array answer of length m where answer[i] is the answer to the ith query.


class CycleLengthQueriesInATree {
    public int[] cycleLengthQueries(int n, int[][] queries) {
        int m = queries.length;
        int[] ans = new int[m];
        int[] parent = new int[1 << n];
        for(int i = 0; i < (1 << n); i++){
            parent[i] = i;
        }
        for(int i = 0; i < m; i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int pa = find(parent, a);
            int pb = find(parent, b);
            if(pa == pb){
                ans[i] = -1;
            }else{
                parent[pa] = pb;
            }
        }
        for(int i = 0; i < (1 << n); i++){
            parent[i] = i;
        }
        for(int i = m - 1; i >= 0; i--){
            int a = queries[i][0];
            int b = queries[i][1];
            int pa = find(parent, a);
            int pb = find(parent, b);
            if(pa == pb){
                ans[i] = -1;
            }else{
                parent[pa] = pb;
                ans[i] = ans[i] == -1 ? 1 : ans[i] + 1;
            }
        }
        return ans;
        
    }
}
     
    