/**https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/ */
//You are given an integer array nums (0-indexed). In one operation, you can choose an element of the array and increment it by 1._x000D_
//_x000D_
//_x000D_
//	For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3]._x000D_
//_x000D_
//_x000D_
//Return the minimum number of operations needed to make nums strictly increasing._x000D_
//_x000D_
//An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of length 1 is trivially strictly increasing._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: nums = [1,1,1]_x000D_
//Output: 3_x000D_
//Explanation: You can do the following operations:_x000D_
//1) Increment nums[2], so nums becomes [1,1,2]._x000D_
//2) Increment nums[1], so nums becomes [1,2,2]._x000D_
//3) Increment nums[2], so nums becomes [1,2,3]._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: nums = [1,5,2,4,1]_x000D_
//Output: 14_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: nums = [8]_x000D_
//Output: 0_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= nums.length <= 5000_x000D_
//	1 <= nums[i] <= 104_x000D_
/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let count = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            count += nums[i] - nums[i + 1] + 1;
            nums[i + 1] = nums[i] + 1;
        }
    }
    return count;
};