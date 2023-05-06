/**https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ */
//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].
//You must write an algorithm with O(log n) runtime complexity.


/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let result = [-1, -1];
    if(nums.length == 0){
        return result;
    }
    let left = 0;
    let right = nums.length - 1;
    while(left < right){
        let mid = left + Math.floor((right - left) / 2);
        if(nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    if(nums[left] != target){
        return result;
    }
    result[0] = left;
    right = nums.length - 1;
    while(left < right){
        let mid = left + Math.floor((right - left) / 2) + 1;
        if(nums[mid] > target){
            right = mid - 1;
        }else{
            left = mid;
        }
    }
    result[1] = right;
    return result;    
};

    