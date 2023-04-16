/**https://leetcode.com/problems/maximum-path-quality-of-a-graph/ */
//There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed integer array values where values[i] is the value of the ith node. You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the nodes uj and vj, and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.
//A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds to complete. You may visit the same node multiple times. The quality of a valid path is the sum of the values of the unique nodes visited in the path (each node's value is added at most once to the sum).
//Return the maximum quality of a valid path.
//Note: There are at most four edges connected to each node.


/**
 * @param {number[]} values
 * @param {number[][]} edges
 * @param {number} maxTime
 * @return {number}
 */
var maximalPathQuality = function(values, edges, maxTime) {
    let n = values.length;
    let adj = new Array(n);
    for(let i = 0; i < n; i++){
        adj[i] = [];
    }
    for(let [u, v, t] of edges){
        adj[u].push([v, t]);
        adj[v].push([u, t]);
    }
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(maxTime + 1).fill(-1);
    }
    dp[0][0] = values[0];
    let ans = 0;
    for(let i = 0; i < n; i++){
        for(let j = 0; j <= maxTime; j++){
            if(dp[i][j] == -1) continue;
            ans = Math.max(ans, dp[i][j]);
            for(let [v, t] of adj[i]){
                if(j + t <= maxTime){
                    dp[v][j + t] = Math.max(dp[v][j + t], dp[i][j] + values[v]);
                }
            }
        }
    }
    return ans;
    
};

    