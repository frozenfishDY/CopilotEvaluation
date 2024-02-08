/**https://leetcode.com/problems/maximum-score-of-a-good-subarray/ */
//You are given an array of integers nums (0-indexed) and an integer k.
//The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
//Return the maximum possible score of a good subarray.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumScore = function(nums, k) {
    let result = 0;
    let min = nums[k];
    for (let i = k; i < nums.length; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
        result = Math.max(result, min * (i - k + 1));
    }
    min = nums[k];
    for (let i = k; i >= 0; i--) {
        if (nums[i] < min) {
            min = nums[i];
        }
        result = Math.max(result, min * (k - i + 1));
    }
    return result;
    
};

    