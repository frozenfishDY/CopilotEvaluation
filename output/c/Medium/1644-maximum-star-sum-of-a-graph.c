/**https://leetcode.com/problems/maximum-star-sum-of-a-graph/ */
//There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.
//You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.
//The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node.


int maxStarSum(int* vals, int valsSize, int** edges, int edgesSize, int* edgesColSize, int k){
    int result = 0;
    int dp[valsSize];
    for(int i = 0; i < valsSize; i++){
        dp[i] = 0;
    }
    for(int i = 1; i < valsSize; i++){
        for(int j = 0; j < i; j++){
            if(vals[i] == vals[j] * vals[j]){
                dp[i] = dp[j] + 1;
                result = result > dp[i] ? result : dp[i];
            }
        }
    }
    return result == 0 ? -1 : result + 1;

}

    