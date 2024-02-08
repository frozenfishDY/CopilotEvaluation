/**https://leetcode.com/problems/maximum-building-height/ */
//You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
//However, there are city restrictions on the heights of the new buildings:
//The height of each building must be a non-negative integer.
//The height of the first building must be 0.
//The height difference between any two adjacent buildings cannot exceed 1.
//Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
//It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
//Return the maximum possible height of the tallest building.


/**
 * @param {number} n
 * @param {number[][]} restrictions
 * @return {number}
 */
var maxBuilding = function(n, restrictions) {
    restrictions.push([1, 0]);
    restrictions.sort((a, b) => a[0] - b[0]);
    let m = restrictions.length;
    for(let i = 1; i < m; i++){
        restrictions[i][1] = Math.min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
    }
    for(let i = m - 2; i >= 0; i--){
        restrictions[i][1] = Math.min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
    }
    let result = 0;
    for(let i = 1; i < m; i++){
        let diff = restrictions[i][0] - restrictions[i - 1][0];
        let heightDiff = Math.abs(restrictions[i][1] - restrictions[i - 1][1]);
        result = Math.max(result, Math.max(restrictions[i][1], restrictions[i - 1][1]) + Math.floor((diff - heightDiff) / 2));
    }
    result = Math.max(result, restrictions[m - 1][1] + n - restrictions[m - 1][0]);
    return result;
    
};

    