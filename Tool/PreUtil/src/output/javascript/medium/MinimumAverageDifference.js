/**https://leetcode.com/problems/minimum-average-difference/ */
//You are given a 0-indexed integer array nums of length n.
//The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.
//Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.
//Note:
//The absolute difference of two numbers is the absolute value of their difference.
//The average of n elements is the sum of the n elements divided (integer division) by n.
//The average of 0 elements is considered to be 0.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumAverageDifference = function(nums) {
    let n = nums.length;
    let prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    let min = Infinity;
    let result = 0;
    for (let i = 0; i < n - 1; i++) {
        let left = Math.floor(prefix[i + 1] / (i + 1));
        let right = Math.floor((prefix[n] - prefix[i + 1]) / (n - i - 1));
        let diff = Math.abs(left - right);
        if (diff < min) {
            min = diff;
            result = i;
        }
    }
    return result;
    
};

    