/**https://leetcode.com/problems/sum-of-beauty-in-the-array/ */
//You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:
//2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
//1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
//0, if none of the previous conditions holds.
//Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.


/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfBeauties = function(nums) {
    let max = nums[0];
    let min = nums[nums.length - 1];
    let maxArr = [max];
    let minArr = [min];
    for (let i = 1; i < nums.length; i++) {
        max = Math.max(max, nums[i]);
        maxArr.push(max);
    }
    for (let i = nums.length - 2; i >= 0; i--) {
        min = Math.min(min, nums[i]);
        minArr.unshift(min);
    }
    let count = 0;
    for (let i = 1; i < nums.length - 1; i++) {
        if (nums[i] > maxArr[i - 1] && nums[i] < minArr[i + 1]) {
            count += 2;
        } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
            count++;
        }
    }
    return count;
    
};

    