/**https://leetcode.com/problems/product-of-array-except-self/ */
//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//You must write an algorithm that runs in O(n) time and without using the division operation.


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let n = nums.length;
    let left = new Array(n).fill(1);
    let right = new Array(n).fill(1);
    let result = new Array(n).fill(1);
    for(let i = 1; i < n; i++){
        left[i] = left[i - 1] * nums[i - 1];
    }
    for(let i = n - 2; i >= 0; i--){
        right[i] = right[i + 1] * nums[i + 1];
    }
    for(let i = 0; i < n; i++){
        result[i] = left[i] * right[i];
    }
    return result;
    
};

    