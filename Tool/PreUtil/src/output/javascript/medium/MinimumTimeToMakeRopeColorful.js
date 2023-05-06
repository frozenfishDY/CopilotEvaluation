/**https://leetcode.com/problems/minimum-time-to-make-rope-colorful/ */
//Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
//Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
//Return the minimum time Bob needs to make the rope colorful.


/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(colors, neededTime) {
    let n = colors.length;
    let dp = new Array(n).fill(Infinity);
    let res = Infinity;
    let sum = 0;
    let map = new Map();
    map.set(0, -1);
    for (let i = 0; i < n; i++) {
        sum += colors[i];
        if (map.has(sum - neededTime)) {
            let j = map.get(sum - neededTime);
            if (j >= 0) {
                dp[i] = i - j;
                if (j > 0) {
                    dp[i] += dp[j - 1];
                }
            }
        }
        if (i > 0) {
            dp[i] = Math.min(dp[i], dp[i - 1]);
        }
        map.set(sum, i);
    }
    return dp[n - 1] === Infinity ? -1 : dp[n - 1];
    
};

    