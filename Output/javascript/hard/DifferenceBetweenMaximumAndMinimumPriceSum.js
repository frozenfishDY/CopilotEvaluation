/**https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/ */
//There exists an undirected and initially unrooted tree with n nodes indexed from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//Each node has an associated price. You are given an integer array price, where price[i] is the price of the ith node.
//The price sum of a given path is the sum of the prices of all nodes lying on that path.
//The tree can be rooted at any node root of your choice. The incurred cost after choosing root is the difference between the maximum and minimum price sum amongst all paths starting at root.
//Return the maximum possible cost amongst all possible root choices.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} price
 * @return {number}
 */
var maxOutput = function(n, edges, price) {
    let graph = new Array(n);
    for(let i = 0; i < n; i++){
        graph[i] = [];
    }
    for(let i = 0; i < edges.length; i++){
        graph[edges[i][0]].push(edges[i][1]);
        graph[edges[i][1]].push(edges[i][0]);
    }
    let max = new Array(n).fill(0);
    let min = new Array(n).fill(0);
    let visited = new Array(n).fill(false);
    let dfs = function(node){
        visited[node] = true;
        max[node] = price[node];
        min[node] = price[node];
        for(let i = 0; i < graph[node].length; i++){
            if(!visited[graph[node][i]]){
                dfs(graph[node][i]);
                max[node] = Math.max(max[node], max[graph[node][i]]);
                min[node] = Math.min(min[node], min[graph[node][i]]);
            }
        }
    };
    dfs(0);
    let result = 0;
    for(let i = 0; i < n; i++){
        result = Math.max(result, max[i] - min[i]);
    }
    return result;
    
};

    