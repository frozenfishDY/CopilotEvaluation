/**https://leetcode.com/problems/maximum-product-of-three-numbers/ */
//Given an integer array nums, find three numbers whose product is maximum and return the maximum product.


/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumProduct = function(nums) {
    let max1 = -Infinity;
    let max2 = -Infinity;
    let max3 = -Infinity;
    let min1 = Infinity;
    let min2 = Infinity;
    for(let i = 0; i < nums.length; i++){
        if(nums[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }else if(nums[i] > max2){
            max3 = max2;
            max2 = nums[i];
        }else if(nums[i] > max3){
            max3 = nums[i];
        }
        if(nums[i] < min1){
            min2 = min1;
            min1 = nums[i];
        }else if(nums[i] < min2){
            min2 = nums[i];
        }
    }
    return Math.max(max1 * max2 * max3, max1 * min1 * min2);
    
};

    