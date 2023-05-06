/**https://leetcode.com/problems/steps-to-make-array-non-decreasing/ */
//You are given a 0-indexed integer array nums. In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.
//Return the number of steps performed until nums becomes a non-decreasing array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var totalSteps = function(nums) {
    let n = nums.length;
    let count = 0;
    let left = 0;
    let right = n - 1;
    let max = -Infinity;
    while (left < right) {
        if (nums[left] < nums[right]) {
            max = Math.max(max, nums[left]);
            left++;
        } else if (nums[left] > nums[right]) {
            max = Math.max(max, nums[right]);
            right--;
        } else {
            max = Math.max(max, nums[left]);
            left++;
            right--;
        }
        count++;
    }
    if (left === right) {
        max = Math.max(max, nums[left]);
    }
    return count;
    
    
};

    