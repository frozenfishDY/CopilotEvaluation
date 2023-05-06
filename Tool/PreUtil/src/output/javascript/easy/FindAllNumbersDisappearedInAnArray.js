/**https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/ */
//Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    let map = {};
    for(let i = 0; i < nums.length; i++){
        map[nums[i]] = 1;
    }
    let arr = [];
    for(let i = 1; i <= nums.length; i++){
        if(map[i] == undefined){
            arr.push(i);
        }
    }
    return arr;
    
};

    