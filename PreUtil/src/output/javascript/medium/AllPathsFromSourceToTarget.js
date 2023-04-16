/**https://leetcode.com/problems/all-paths-from-source-to-target/ */
//Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
//The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).


/**
 * @param {number[][]} graph
 * @return {number[][]}
 */
var allPathsSourceTarget = function(graph) {
    let n = graph.length;
    let result = [];
    let path = [];
    function dfs(node){
        path.push(node);
        if(node == n - 1){
            result.push([...path]);
        }else{
            for(let i = 0; i < graph[node].length; i++){
                dfs(graph[node][i]);
            }
        }
        path.pop();
    }
    dfs(0);
    return result;
    
};

    