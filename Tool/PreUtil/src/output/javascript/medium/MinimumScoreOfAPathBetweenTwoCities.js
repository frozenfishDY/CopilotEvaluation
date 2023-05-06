/**https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/ */
//You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
//The score of a path between two cities is defined as the minimum distance of a road in this path.
//Return the minimum possible score of a path between cities 1 and n.
//Note:
//A path is a sequence of roads between two cities.
//It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
//The test cases are generated such that there is at least one path between 1 and n.


/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var minScore = function(n, roads) {
    let graph = new Array(n).fill(0).map(() => new Array());
    let dist = new Array(n).fill(Infinity);
    for(let i = 0; i < roads.length; i++){
        let [a, b, d] = roads[i];
        graph[a - 1].push([b - 1, d]);
        graph[b - 1].push([a - 1, d]);
    }
    dijkstra(0, graph, dist);
    return dist[n - 1];
    
    
    
};

    