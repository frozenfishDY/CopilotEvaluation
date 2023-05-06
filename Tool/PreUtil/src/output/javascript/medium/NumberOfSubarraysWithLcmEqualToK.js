/**https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/ */
//Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.
//A subarray is a contiguous non-empty sequence of elements within an array.
//The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.
// 
//Example 1:
//Input: nums = [3,6,2,7,1], k = 6
//Output: 4
//Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//- [3,6,2,7,1]
//Example 2:
//Input: nums = [3], k = 2
//Output: 0
//Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarrayLCM = function(nums, k) {
    let count = 0;
    let lcm = 1;
    let map = new Map();
    map.set(0, 1);
    for (let i = 0; i < nums.length; i++) {
        lcm = lcm * nums[i] / gcd(lcm, nums[i]);
        if (lcm % k === 0) {
            count += map.get(lcm / k) || 0;
        }
        map.set(lcm, (map.get(lcm) || 0) + 1);
    }
    return count;
    
};

    