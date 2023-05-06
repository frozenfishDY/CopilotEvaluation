/**https://leetcode.com/problems/find-eventual-safe-states/ */
//There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
//A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
//Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function(graph) {
    let n = graph.length;
    let color = new Array(n).fill(0);
    let result = [];
    for(let i = 0; i < n; i++){
        if(dfs(i)){
            result.push(i);
        }
    }
    return result;
    
    function dfs(node){
        if(color[node] > 0){
            return color[node] == 2;
        }
        color[node] = 1;
        for(let i = 0; i < graph[node].length; i++){
            if(color[graph[node][i]] == 2){
                continue;
            }
            if(color[graph[node][i]] == 1 || !dfs(graph[node][i])){
                return false;
            }
        }
        color[node] = 2;
        return true;
    }
    
};

    