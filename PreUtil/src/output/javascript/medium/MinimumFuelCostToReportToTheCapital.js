/**https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/ */
//There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
//There is a meeting for the representatives of each city. The meeting is in the capital city.
//There is a car in each city. You are given an integer seats that indicates the number of seats in each car.
//A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.
//Return the minimum number of liters of fuel to reach the capital city.


/**
 * @param {number[][]} roads
 * @param {number} seats
 * @return {number}
 */
var minimumFuelCost = function(roads, seats) {
    let n = roads.length + 1;
    let graph = new Array(n);
    for (let i = 0; i < n; i++) {
        graph[i] = new Array();
    }
    for (let i = 0; i < roads.length; i++) {
        graph[roads[i][0]].push(roads[i][1]);
        graph[roads[i][1]].push(roads[i][0]);
    }
    let dp = new Array(n);
    for (let i = 0; i < n; i++) {
        dp[i] = new Array(seats + 1).fill(Infinity);
    }
    let visited = new Array(n).fill(false);
    let min = Infinity;
    dfs(0, 0, 0, graph, dp, visited, seats);
    for (let i = 1; i <= seats; i++) {
        min = Math.min(min, dp[0][i]);
    }
    return min;
    
    
};

    