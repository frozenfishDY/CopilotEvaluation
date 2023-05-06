/**https://leetcode.com/problems/sum-of-distances-in-tree/ */
//There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var sumOfDistancesInTree = function(n, edges) {
    let graph = new Array(n);
    for(let i = 0; i < n; i++){
        graph[i] = [];
    }
    for(let i = 0; i < edges.length; i++){
        graph[edges[i][0]].push(edges[i][1]);
        graph[edges[i][1]].push(edges[i][0]);
    }
    let count = new Array(n).fill(1);
    let res = new Array(n).fill(0);
    let visited = new Array(n).fill(false);
    let dfs = function(node){
        visited[node] = true;
        for(let i = 0; i < graph[node].length; i++){
            if(!visited[graph[node][i]]){
                dfs(graph[node][i]);
                count[node] += count[graph[node][i]];
                res[node] += res[graph[node][i]] + count[graph[node][i]];
            }
        }
    };
    let dfs2 = function(node){
        visited[node] = true;
        for(let i = 0; i < graph[node].length; i++){
            if(!visited[graph[node][i]]){
                res[graph[node][i]] = res[node] - count[graph[node][i]] + n - count[graph[node][i]];
                dfs2(graph[node][i]);
            }
        }
    };
    dfs(0);
    visited = new Array(n).fill(false);
    dfs2(0);
    return res;
    
};

    