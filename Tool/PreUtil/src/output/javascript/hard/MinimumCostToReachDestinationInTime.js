/**https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/ */
//There is a country of n cities numbered from 0 to n - 1 where all the cities are connected by bi-directional roads. The roads are represented as a 2D integer array edges where edges[i] = [xi, yi, timei] denotes a road between cities xi and yi that takes timei minutes to travel. There may be multiple roads of differing travel times connecting the same two cities, but no road connects a city to itself.
//Each time you pass through a city, you must pay a passing fee. This is represented as a 0-indexed integer array passingFees of length n where passingFees[j] is the amount of dollars you must pay when you pass through city j.
//In the beginning, you are at city 0 and want to reach city n - 1 in maxTime minutes or less. The cost of your journey is the summation of passing fees for each city that you passed through at some moment of your journey (including the source and destination cities).
//Given maxTime, edges, and passingFees, return the minimum cost to complete your journey, or -1 if you cannot complete it within maxTime minutes.


/**
 * @param {number} maxTime
 * @param {number[][]} edges
 * @param {number[]} passingFees
 * @return {number}
 */
var minCost = function(maxTime, edges, passingFees) {
    let n = passingFees.length;
    let dp = new Array(n).fill(Infinity);
    dp[0] = passingFees[0];
    let graph = new Array(n);
    for(let i = 0; i < n; i++){
        graph[i] = [];
    }
    for(let i = 0; i < edges.length; i++){
        let u = edges[i][0];
        let v = edges[i][1];
        let w = edges[i][2];
        graph[u].push([v, w]);
        graph[v].push([u, w]);
    }
    let pq = new PriorityQueue((a, b) => a[0] < b[0]);
    pq.push([0, 0, 0]);
    while(!pq.isEmpty()){
        let [cost, time, u] = pq.pop();
        if(time > maxTime) continue;
        if(u == n - 1) return cost;
        for(let i = 0; i < graph[u].length; i++){
            let v = graph[u][i][0];
            let w = graph[u][i][1];
            if(dp[v] > cost + passingFees[v]){
                dp[v] = cost + passingFees[v];
                pq.push([dp[v], time + w, v]);
            }
        }
    }
    return -1;
    
    
};

    