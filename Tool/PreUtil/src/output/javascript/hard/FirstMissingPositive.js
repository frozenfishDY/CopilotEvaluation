/**https://leetcode.com/problems/first-missing-positive/ */
//Given an unsorted integer array nums, return the smallest missing positive integer.
//You must implement an algorithm that runs in O(n) time and uses constant extra space.


/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    let len = nums.length;
    for(let i = 0; i < len; i++){
        while(nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i]){
            let temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }
    for(let i = 0; i < len; i++){
        if(nums[i] != i + 1){
            return i + 1;
        }
    }
    return len + 1;
    
};

    