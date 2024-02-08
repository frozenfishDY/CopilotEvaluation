/**https://leetcode.com/problems/is-graph-bipartite/ */
//There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
//There are no self-edges (graph[u] does not contain u).
//There are no parallel edges (graph[u] does not contain duplicate values).
//If v is in graph[u], then u is in graph[v] (the graph is undirected).
//The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
//A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
//Return true if and only if it is bipartite.


/**
 * @param {number[][]} graph
 * @return {boolean}
 */
var isBipartite = function(graph) {
    let n = graph.length;
    let color = new Array(n).fill(-1);
    for(let i = 0; i < n; i++){
        if(color[i] == -1){
            let queue = [];
            queue.push(i);
            color[i] = 0;
            while(queue.length > 0){
                let node = queue.shift();
                for(let j = 0; j < graph[node].length; j++){
                    if(color[graph[node][j]] == -1){
                        color[graph[node][j]] = color[node] ^ 1;
                        queue.push(graph[node][j]);
                    }else if(color[graph[node][j]] == color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
    
};

    