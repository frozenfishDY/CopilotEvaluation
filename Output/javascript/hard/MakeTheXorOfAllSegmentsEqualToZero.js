/**https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/ */
//You are given an array nums and an integer k . The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].
//Return the minimum number of elements to change in the array such that the XOR of all segments of size k is equal to zero.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minChanges = function(nums, k) {
    let result = 0;
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        let key = i % k;
        if (!map.has(key)) {
            map.set(key, new Map());
        }
        let subMap = map.get(key);
        if (!subMap.has(nums[i])) {
            subMap.set(nums[i], 1);
        } else {
            subMap.set(nums[i], subMap.get(nums[i]) + 1);
        }
    }
    let max = 0;
    let maxKey = 0;
    for (let [key, value] of map) {
        for (let [subKey, subValue] of value) {
            if (subValue > max) {
                max = subValue;
                maxKey = subKey;
            }
        }
        result += nums.length / k - max;
        max = 0;
        maxKey = 0;
    }
    return result;
    
};

    