/**https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/ */
//An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.
//Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .
//Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.


class CheckingExistenceOfEdgeLengthLimitedPaths {
    public boolean[] distanceLimitedPathsExist(int n, int[][] edgeList, int[][] queries) {
        int m = queries.length;
        int[] res = new int[m];
        int[] parent = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        Arrays.sort(edgeList, (a, b) -> a[2] - b[2]);
        int[][] q = new int[m][4];
        for(int i = 0; i < m; i++){
            q[i][0] = queries[i][0];
            q[i][1] = queries[i][1];
            q[i][2] = queries[i][2];
            q[i][3] = i;
        }
        Arrays.sort(q, (a, b) -> a[2] - b[2]);
        int j = 0;
        for(int i = 0; i < m; i++){
            while(j < edgeList.length && edgeList[j][2] < q[i][2]){
                union(parent, edgeList[j][0], edgeList[j][1]);
                j++;
            }
            res[q[i][3]] = find(parent, q[i][0]) == find(parent, q[i][1]) ? 1 : 0;
        }
        boolean[] ans = new boolean[m];
        for(int i = 0; i < m; i++){
            ans[i] = res[i] == 1;
        }
        return ans;
        
    }
}
     
    