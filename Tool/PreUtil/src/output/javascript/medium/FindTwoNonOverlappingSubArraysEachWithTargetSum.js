/**https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/ */
//You are given an array of integers arr and an integer target.
//You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
//Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.


/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var minSumOfLengths = function(arr, target) {
    let n = arr.length;
    let dp = new Array(n).fill(Infinity);
    let res = Infinity;
    let sum = 0;
    let map = new Map();
    map.set(0, -1);
    for (let i = 0; i < n; i++) {
        sum += arr[i];
        if (map.has(sum - target)) {
            let j = map.get(sum - target);
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

    