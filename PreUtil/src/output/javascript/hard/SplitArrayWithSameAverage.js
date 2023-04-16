/**https://leetcode.com/problems/split-array-with-same-average/ */
//You are given an integer array nums.
//You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
//Return true if it is possible to achieve that and false otherwise.
//Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.


/**
 * @param {number[]} nums
 * @return {boolean}
 */
var splitArraySameAverage = function(nums) {
    const sum = nums.reduce((acc, cur) => acc + cur, 0);
    const n = nums.length;
    const dp = new Array(sum + 1).fill(false);
    dp[0] = true;
    
    for (let i = 0; i < n; i++) {
        for (let j = sum; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    
    for (let i = 1; i <= sum / 2; i++) {
        if (dp[i] && i * n === sum) {
            return true;
        }
    }
    
    return false;
    
};

    