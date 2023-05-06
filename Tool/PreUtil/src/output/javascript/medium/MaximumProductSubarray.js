/**https://leetcode.com/problems/maximum-product-subarray/ */
//Given an integer array nums, find a subarray that has the largest product, and return the product.
//The test cases are generated so that the answer will fit in a 32-bit integer.


/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    let max = nums[0];
    let min = nums[0];
    let result = nums[0];
    for(let i = 1; i < nums.length; i++){
        let temp = max;
        max = Math.max(nums[i], Math.max(max * nums[i], min * nums[i]));
        min = Math.min(nums[i], Math.min(temp * nums[i], min * nums[i]));
        result = Math.max(result, max);
    }
    return result;
    
};

    