/**https://leetcode.com/problems/tuple-with-same-product/ */
//Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.


/**
 * @param {number[]} nums
 * @return {number}
 */
var tupleSameProduct = function(nums) {
    let n = nums.length;
    let map = new Map();
    let result = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let product = nums[i] * nums[j];
            if (map.has(product)) {
                result += 8 * map.get(product);
                map.set(product, map.get(product) + 1);
            } else {
                map.set(product, 1);
            }
        }
    }
    return result;
    
};

    