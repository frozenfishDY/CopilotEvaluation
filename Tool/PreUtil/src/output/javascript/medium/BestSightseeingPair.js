/**https://leetcode.com/problems/best-sightseeing-pair/ */
//You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
//The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
//Return the maximum score of a pair of sightseeing spots.


/**
 * @param {number[]} values
 * @return {number}
 */
var maxScoreSightseeingPair = function(values) {
    let n = values.length;
    let dp = new Array(n + 1).fill(0);
    let result = 0;
    for(let i = 1; i < n; i++){
        dp[i] = Math.max(dp[i - 1], values[i - 1] + i - 1);
        result = Math.max(result, dp[i] + values[i] - i);
    }
    return result;
    
};

    