/**https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/ */
//You are given two integer arrays nums1 and nums2 of length n.
//The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).
//For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
//Rearrange the elements of nums2 such that the resulting XOR sum is minimized.
//Return the XOR sum after the rearrangement.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minimumXORSum = function(nums1, nums2) {
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

    