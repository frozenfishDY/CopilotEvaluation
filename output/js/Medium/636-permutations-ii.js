/**https://leetcode.com/problems/permutations-ii/ */
//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.


/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    let result = [];
    if(nums.length == 0){
        return result;
    }
    nums.sort((a, b) => a - b);
    let current = [];
    let visited = new Array(nums.length);
    helper(nums, current, result, visited);
    return result;
    
    
};

    