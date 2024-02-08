/**https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/ */
//You are given an integer array nums sorted in non-decreasing order.
//Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.
//In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSumAbsoluteDifferences = function(nums) {
    let n = nums.length;
    let result = new Array(n).fill(0);
    let prefix = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    let suffix = new Array(n).fill(0);
    for (let i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + nums[i + 1];
    }
    for (let i = 0; i < n; i++) {
        result[i] = nums[i] * i - prefix[i] + suffix[i] - nums[i] * (n - i - 1);
    }
    return result;
    
};

    