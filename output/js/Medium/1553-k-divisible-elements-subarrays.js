/**https://leetcode.com/problems/k-divisible-elements-subarrays/ */
//Given an integer array nums and two integers k and p, return the number of distinct subarrays which have at most k elements divisible by p.
//Two arrays nums1 and nums2 are said to be distinct if:
//They are of different lengths, or
//There exists at least one index i where nums1[i] != nums2[i].
//A subarray is defined as a non-empty contiguous sequence of elements in an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} p
 * @return {number}
 */
var countDistinct = function(nums, k, p) {
    let map = {};
    let count = 0;
    let sum = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        let mod = sum % p;
        if (map[mod] === undefined) {
            map[mod] = 1;
        } else {
            map[mod]++;
        }
        if (i >= k) {
            let prevMod = (sum - nums[i - k]) % p;
            map[prevMod]--;
        }
        if (i >= k - 1) {
            for (let key in map) {
                if (map[key] > 0) {
                    count += map[key];
                }
            }
        }
    }
    return count;
    
};

    