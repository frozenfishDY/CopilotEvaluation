/**https://leetcode.com/problems/find-center-of-star-graph/ */
//There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
//You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.


/**
 * @param {number[][]} edges
 * @return {number}
 */
var findCenter = function(edges) {
    let map = {};
    for(let i = 0; i < edges.length; i++){
        let edge = edges[i];
        for(let j = 0; j < edge.length; j++){
            let node = edge[j];
            if(map[node] == undefined){
                map[node] = 1;
            }else{
                map[node]++;
            }
        }
    }
    for(let key in map){
        if(map[key] == edges.length){
            return key;
        }
    }
    return 0;
    
};

    