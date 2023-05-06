/**https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/ */
//You are given an undirected graph. You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
//A connected trio is a set of three nodes where there is an edge between every pair of them.
//The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
//Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var minTrioDegree = function(n, edges) {
    let map = new Map();
    for(let i = 0; i < n; i++){
        map.set(i, new Set());
    }
    for(let i = 0; i < edges.length; i++){
        let x = edges[i][0] - 1;
        let y = edges[i][1] - 1;
        map.get(x).add(y);
        map.get(y).add(x);
    }
    let min = Number.MAX_SAFE_INTEGER;
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            for(let k = j + 1; k < n; k++){
                if(map.get(i).has(j) && map.get(i).has(k) && map.get(j).has(k)){
                    let degree = map.get(i).size + map.get(j).size + map.get(k).size - 6;
                    min = Math.min(min, degree);
                }
            }
        }
    }
    return min == Number.MAX_SAFE_INTEGER ? -1 : min;
    
};

    