/**https://leetcode.com/problems/removing-minimum-and-maximum-from-array/ */
//You are given a 0-indexed array of distinct integers nums.
//There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
//A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
//Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDeletions = function(nums) {
    let n = nums.length;
    let min = nums[0];
    let max = nums[n - 1];
    let left = 0;
    let right = n - 1;
    let count = 0;
    while (left < right) {
        if (min < max) {
            left++;
            min = Math.min(min, nums[left]);
        } else if (min > max) {
            right--;
            max = Math.max(max, nums[right]);
        } else {
            left++;
            right--;
            min = Math.min(min, nums[left]);
            max = Math.max(max, nums[right]);
        }
        count++;
    }
    return count;
    
};

    