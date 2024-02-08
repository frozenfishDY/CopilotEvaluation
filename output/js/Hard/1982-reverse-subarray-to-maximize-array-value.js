/**https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/ */
//You are given an integer array nums. The value of this array is defined as the sum of |nums[i] - nums[i + 1]| for all 0 <= i < nums.length - 1.
//You are allowed to select any subarray of the given array and reverse it. You can perform this operation only once.
//Find maximum possible value of the final array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var maxValueAfterReverse = function(nums) {
    let ans = 0;
    let max = -Infinity;
    let min = Infinity;
    let n = nums.length;
    for(let i = 0; i < n - 1; i++){
        ans += Math.abs(nums[i] - nums[i + 1]);
        max = Math.max(max, Math.max(nums[i], nums[i + 1]));
        min = Math.min(min, Math.min(nums[i], nums[i + 1]));
    }
    let ans1 = ans;
    let ans2 = ans;
    for(let i = 0; i < n - 1; i++){
        ans1 = Math.max(ans1, ans - Math.abs(nums[i] - nums[i + 1]) + Math.abs(nums[i] - max));
        ans1 = Math.max(ans1, ans - Math.abs(nums[i] - nums[i + 1]) + Math.abs(nums[i + 1] - max));
        ans2 = Math.max(ans2, ans - Math.abs(nums[i] - nums[i + 1]) + Math.abs(nums[i] - min));
        ans2 = Math.max(ans2, ans - Math.abs(nums[i] - nums[i + 1]) + Math.abs(nums[i + 1] - min));
    }
    return Math.max(ans1, ans2);
    
    
};

    