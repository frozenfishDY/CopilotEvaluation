/**https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/ */
//Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:
//Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
//Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var numTriplets = function(nums1, nums2) {
    let n = nums1.length;
    let m = nums2.length;
    let res = 0;
    let map1 = new Map();
    let map2 = new Map();
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let product = nums1[i] * nums1[j];
            map1.set(product, (map1.get(product) || 0) + 1);
        }
    }
    for (let i = 0; i < m; i++) {
        for (let j = i + 1; j < m; j++) {
            let product = nums2[i] * nums2[j];
            map2.set(product, (map2.get(product) || 0) + 1);
        }
    }
    for (let i = 0; i < n; i++) {
        let square = nums1[i] * nums1[i];
        if (map2.has(square)) {
            res += map2.get(square);
        }
    }
    for (let i = 0; i < m; i++) {
        let square = nums2[i] * nums2[i];
        if (map1.has(square)) {
            res += map1.get(square);
        }
    }
    return res;
    
};

    