/**https://leetcode.com/problems/redundant-connection/ */
//In this problem, a tree is an undirected graph that is connected and has no cycles.
//You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
//Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.


/**
 * @param {number[][]} edges
 * @return {number[]}
 */
var findRedundantConnection = function(edges) {
    let n = edges.length;
    let parent = new Array(n + 1).fill(0).map((_, index) => index);
    for(let edge of edges){
        let [node1, node2] = edge;
        let parent1 = findParent(node1, parent);
        let parent2 = findParent(node2, parent);
        if(parent1 == parent2){
            return edge;
        }
        parent[parent1] = parent2;
    }
    return [];
    
    
    
};

    