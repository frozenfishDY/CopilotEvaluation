/**https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/ */
//You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
//The length of the subarray is k, and
//All the elements of the subarray are distinct.
//Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
//A subarray is a contiguous non-empty sequence of elements within an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumSubarraySum = function(nums, k) {
    let set = new Set();
    let sum = 0;
    let result = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        set.add(nums[i]);
        if (set.size === k) {
            result = Math.max(result, sum);
            sum -= nums[i - k + 1];
            set.delete(nums[i - k + 1]);
        }
    }
    return result;
    
};

    