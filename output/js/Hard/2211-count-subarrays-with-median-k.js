/**https://leetcode.com/problems/count-subarrays-with-median-k/ */
//You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
//Return the number of non-empty subarrays in nums that have a median equal to k.
//Note:
//The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
//For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
//A subarray is a contiguous part of an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        for (let j = i; j < nums.length; j++) {
            let median = findMedian(nums, i, j);
            if (median == k) {
                result++;
            }
        }
    }
    return result;
    
    
};

    