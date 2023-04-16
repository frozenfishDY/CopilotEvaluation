/**https://leetcode.com/problems/maximum-earnings-from-taxi/ */
//There are n points on a road you are driving your taxi on. The n points on the road are labeled from 1 to n in the direction you are going, and you want to drive from point 1 to point n to make money by picking up passengers. You cannot change the direction of the taxi.
//The passengers are represented by a 0-indexed 2D integer array rides, where rides[i] = [starti, endi, tipi] denotes the ith passenger requesting a ride from point starti to point endi who is willing to give a tipi dollar tip.
//For each passenger i you pick up, you earn endi - starti + tipi dollars. You may only drive at most one passenger at a time.
//Given n and rides, return the maximum number of dollars you can earn by picking up the passengers optimally.
//Note: You may drop off a passenger and pick up a different passenger at the same point.


/**
 * @param {number} n
 * @param {number[][]} rides
 * @return {number}
 */
var maxTaxiEarnings = function(n, rides) {
    let dp = new Array(n + 1).fill(0);
    rides.sort((a, b) => a[1] - b[1]);
    for (let i = 0; i < rides.length; i++) {
        let [start, end, tip] = rides[i];
        let index = binarySearch(rides, start);
        dp[end] = Math.max(dp[end], dp[start] + end - start + tip);
        dp[end] = Math.max(dp[end], dp[rides[index][1]] + end - rides[index][1] + tip);
    }
    return dp[n];
    
    
};

    