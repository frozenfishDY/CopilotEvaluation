/**https://leetcode.com/problems/sum-of-floored-pairs/ */
//Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
//The floor() function returns the integer part of the division.


/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfFlooredPairs = function(nums) {
    let result = 0;
    let max = Math.max(...nums);
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (!map.has(nums[i])) {
            map.set(nums[i], 1);
        } else {
            map.set(nums[i], map.get(nums[i]) + 1);
        }
    }
    let sum = 0;
    for (let i = 1; i <= max; i++) {
        let count = 0;
        for (let j = i; j <= max; j += i) {
            if (map.has(j)) {
                count += map.get(j);
            }
        }
        sum += count;
        result += sum * i;
    }
    return result % 1000000007;
    
};

    