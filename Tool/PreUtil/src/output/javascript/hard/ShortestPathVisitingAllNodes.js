/**https://leetcode.com/problems/shortest-path-visiting-all-nodes/ */
//You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
//Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.


/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function(graph) {
    let n = graph.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < n; j++){
            dp[i].push([]);
            for(let k = 0; k < (1 << n); k++){
                dp[i][j].push(-1);
            }
        }
    }
    let dfs = function(node, mask, steps){
        if(mask === (1 << n) - 1){
            return steps;
        }
        if(dp[node][mask][steps] !== -1){
            return dp[node][mask][steps];
        }
        let result = Infinity;
        for(let i = 0; i < graph[node].length; i++){
            let newMask = mask | (1 << graph[node][i]);
            result = Math.min(result, dfs(graph[node][i], newMask, steps + 1));
        }
        dp[node][mask][steps] = result;
        return result;
    };
    let result = Infinity;
    for(let i = 0; i < n; i++){
        result = Math.min(result, dfs(i, 1 << i, 0));
    }
    return result;
    
};

    