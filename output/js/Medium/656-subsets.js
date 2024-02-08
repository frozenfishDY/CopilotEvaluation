/**https://leetcode.com/problems/subsets/ */
//Given an integer array nums of unique elements, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.


/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let result = [];
    let current = [];
    helper(nums, 0, current, result);
    return result;
    
    
    
};

    