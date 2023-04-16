/**https://leetcode.com/problems/maximum-subarray/ */
//Given an integer array nums, find the subarray with the largest sum, and return its sum.


/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let max = nums[0];
    let sum = nums[0];
    for(let i = 1; i < nums.length; i++){
        sum = Math.max(nums[i], sum + nums[i]);
        max = Math.max(max, sum);
    }
    return max;
    
};

    