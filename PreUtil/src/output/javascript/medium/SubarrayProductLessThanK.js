/**https://leetcode.com/problems/subarray-product-less-than-k/ */
//Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numSubarrayProductLessThanK = function(nums, k) {
    let n = nums.length;
    let result = 0;
    let left = 0;
    let right = 0;
    let product = 1;
    while(right < n){
        product *= nums[right];
        while(left <= right && product >= k){
            product /= nums[left];
            left++;
        }
        result += right - left + 1;
        right++;
    }
    return result;
    
};

    