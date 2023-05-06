/**https://leetcode.com/problems/permutations/ */
//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let result = [];
    if(nums.length == 0){
        return result;
    }
    let current = [];
    let visited = new Array(nums.length);
    helper(nums, current, result, visited);
    return result;
    
    
};

    