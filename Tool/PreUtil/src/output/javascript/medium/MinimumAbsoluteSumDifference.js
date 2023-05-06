/**https://leetcode.com/problems/minimum-absolute-sum-difference/ */
//You are given two positive integer arrays nums1 and nums2, both of length n.
//The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).
//You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.
//Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.
//|x| is defined as:
//x if x >= 0, or
//-x if x < 0.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minAbsoluteSumDiff = function(nums1, nums2) {
    let sum = 0;
    let max = 0;
    let set = new Set(nums1);
    for (let i = 0; i < nums1.length; i++) {
        let diff = Math.abs(nums1[i] - nums2[i]);
        sum = (sum + diff) % 1000000007;
        if (diff > max) {
            for (let num of set) {
                let newDiff = Math.abs(num - nums2[i]);
                max = Math.max(max, diff - newDiff);
            }
        }
    }
    return (sum - max) % 1000000007;
    
};

    