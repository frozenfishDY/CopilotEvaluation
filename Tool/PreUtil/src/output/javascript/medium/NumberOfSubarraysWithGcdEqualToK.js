/**https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The greatest common divisor of an array is the largest integer that evenly divides all the array elements.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarrayGCD = function(nums, k) {
    let count = 0;
    let gcd = 0;
    let map = new Map();
    map.set(0, 1);
    for (let i = 0; i < nums.length; i++) {
        gcd = gcd(nums[i], gcd);
        if (gcd % k === 0) {
            count += map.get(gcd / k) || 0;
        }
        map.set(gcd, (map.get(gcd) || 0) + 1);
    }
    return count;
    
    
    
};

    