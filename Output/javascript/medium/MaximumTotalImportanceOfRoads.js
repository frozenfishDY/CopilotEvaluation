/**https://leetcode.com/problems/maximum-total-importance-of-roads/ */
//You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.
//You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
//You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.
//Return the maximum total importance of all roads possible after assigning the values optimally.


/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var maximumImportance = function(n, roads) {
    let graph = new Graph(n);
    for (let i = 0; i < roads.length; i++) {
        graph.addEdge(roads[i][0], roads[i][1]);
    }
    let max = 0;
    for (let i = 1; i <= n; i++) {
        let sum = 0;
        for (let j = 0; j < n; j++) {
            sum += graph.dijkstra(i, j);
        }
        max = Math.max(max, sum);
    }
    return max;
    
    
};

    