/**https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/ */
//Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.
//An array A is a zigzag array if either:
//	Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
//	OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
//Return the minimum number of moves to transform the given array nums into a zigzag array.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 2
//Explanation: We can decrease 2 to 0 or 3 to 1.
//Example 2:
//Input: nums = [9,6,1,6,2]
//Output: 4
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 1000
/**
 * @param {number[]} nums
 * @return {number}
 */
var movesToMakeZigzag = function(nums) {
    var len = nums.length;
	var ans1 = 0;
	var ans2 = 0;
	for (var i = 0; i < len; i++) {
		var left = i > 0 ? nums[i - 1] : Infinity;
		var right = i < len - 1 ? nums[i + 1] : Infinity;
		ans1 += Math.max(0, nums[i] - Math.min(left, right) + 1);
		if (i > 0 && nums[i - 1] >= nums[i]) {
			ans1 += nums[i - 1] - nums[i] + 1;
		}
		if (i < len - 1 && nums[i + 1] >= nums[i]) {
			ans1 += nums[i + 1] - nums[i] + 1;
		}
	}
	for (var i = 0; i < len; i++) {
		var left = i > 0 ? nums[i - 1] : Infinity;
		var right = i < len - 1 ? nums[i + 1] : Infinity;
		ans2 += Math.max(0, nums[i] - Math.min(left, right) + 1);
		if (i > 0 && nums[i - 1] <= nums[i]) {
			ans2 += nums[i] - nums[i - 1] + 1;
		}
		if (i < len - 1 && nums[i + 1] <= nums[i]) {
			ans2 += nums[i] - nums[i + 1] + 1;
		}
	}
	return Math.min(ans1, ans2);
};