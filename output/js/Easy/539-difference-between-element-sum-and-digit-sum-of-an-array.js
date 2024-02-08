/**https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/ */
//You are given a positive integer array nums.
//The element sum is the sum of all the elements in nums.
//The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
//Return the absolute difference between the element sum and digit sum of nums.
//Note that the absolute difference between two integers x and y is defined as |x - y|.


/**
 * @param {number[]} nums
 * @return {number}
 */
var differenceOfSum = function(nums) {
    let elementSum = 0;
    let digitSum = 0;
    for(let i = 0; i < nums.length; i++){
        elementSum += nums[i];
        digitSum += getDigitSum(nums[i]);
    }
    return Math.abs(elementSum - digitSum);
    
    
};

    