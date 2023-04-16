/**https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/ */
//There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
//Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
//Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} distanceThreshold
 * @return {number}
 */
var findTheCity = function(n, edges, distanceThreshold) {
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Array(n).fill(Infinity);
        dp[i][i] = 0;
    }
    for(let i = 0; i < edges.length; i++){
        let from = edges[i][0];
        let to = edges[i][1];
        let weight = edges[i][2];
        dp[from][to] = weight;
        dp[to][from] = weight;
    }
    for(let k = 0; k < n; k++){
        for(let i = 0; i < n; i++){
            for(let j = 0; j < n; j++){
                dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    let result = Infinity;
    let resultIndex = -1;
    for(let i = 0; i < n; i++){
        let count = 0;
        for(let j = 0; j < n; j++){
            if(dp[i][j] <= distanceThreshold){
                count++;
            }
        }
        if(count <= result){
            result = count;
            resultIndex = i;
        }
    }
    return resultIndex;
    
};

    