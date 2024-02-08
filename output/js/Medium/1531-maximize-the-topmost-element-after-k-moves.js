/**https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/ */
//You are given a 0-indexed integer array nums representing the contents of a pile, where nums[0] is the topmost element of the pile.
//In one move, you can perform either of the following:
//If the pile is not empty, remove the topmost element of the pile.
//If there are one or more removed elements, add any one of them back onto the pile. This element becomes the new topmost element.
//You are also given an integer k, which denotes the total number of moves to be made.
//Return the maximum value of the topmost element of the pile possible after exactly k moves. In case it is not possible to obtain a non-empty pile after k moves, return -1.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumTop = function(nums, k) {
    let n = nums.length;
    let result = -1;
    let left = 0;
    let right = n - 1;
    let count = 0;
    while (left < right) {
        if (nums[left] < nums[right]) {
            left++;
        } else if (nums[left] > nums[right]) {
            right--;
        } else {
            left++;
            right--;
        }
        count++;
    }
    if (left === right) {
        result = nums[left];
    }
    if (k > count) {
        k = k - count;
        if (k % 2 === 1) {
            result = -1;
        }
    }
    return result;
    
};

    