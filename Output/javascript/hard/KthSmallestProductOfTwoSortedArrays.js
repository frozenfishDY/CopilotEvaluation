/**https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/ */
//Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number}
 */
var kthSmallestProduct = function(nums1, nums2, k) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < nums1.length; i++) {
        for (let j = 0; j < nums2.length; j++) {
            let xor = nums1[i] ^ nums2[j];
            if (xor >= low && xor <= high) {
                result++;
            }
        }
    }
    return result;
    
};

    