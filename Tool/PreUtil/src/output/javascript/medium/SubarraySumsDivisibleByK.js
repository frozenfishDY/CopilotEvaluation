/**https://leetcode.com/problems/subarray-sums-divisible-by-k/ */
//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
//A subarray is a contiguous part of an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function(nums, k) {
    let count = new Array(k).fill(0);
    count[0] = 1;
    let sum = 0;
    let ans = 0;
    for(let i = 0; i < nums.length; i++){
        sum += nums[i];
        let mod = ((sum % k) + k) % k;
        ans += count[mod];
        count[mod]++;
    }
    return ans;
    
};

    