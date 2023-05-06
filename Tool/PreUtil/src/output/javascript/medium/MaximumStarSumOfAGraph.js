/**https://leetcode.com/problems/maximum-star-sum-of-a-graph/ */
//There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.
//You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.
//The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node.


/**
 * @param {number[]} vals
 * @param {number[][]} edges
 * @param {number} k
 * @return {number}
 */
var maxStarSum = function(vals, edges, k) {
    let n = vals.length;
    let result = 0;
    let graph = new Array(n).fill(0).map(() => new Array());
    for(let i = 0; i < edges.length; i++){
        let [a, b] = edges[i];
        graph[a].push(b);
        graph[b].push(a);
    }
    let dp = new Array(n).fill(0).map(() => new Array(k + 1).fill(0));
    let dfs = (node, parent) => {
        for(let i = 0; i < graph[node].length; i++){
            let child = graph[node][i];
            if(child != parent){
                dfs(child, node);
                for(let j = k; j >= 1; j--){
                    for(let l = 0; l < j; l++){
                        dp[node][j] = Math.max(dp[node][j], dp[node][j - l - 1] + dp[child][l]);
                    }
                }
            }
        }
        for(let i = k; i >= 1; i--){
            dp[node][i] = dp[node][i - 1] + vals[node];
        }
        dp[node][0] = 0;
    }
    dfs(0, -1);
    return dp[0][k];
    
};

    