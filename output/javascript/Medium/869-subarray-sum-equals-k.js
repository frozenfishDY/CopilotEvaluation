/**https://leetcode.com/problems/subarray-sum-equals-k/ */
//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,1,1], k = 2
//Output: 2
//Example 2:
//Input: nums = [1,2,3], k = 3
//Output: 2
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	-1000 <= nums[i] <= 1000
//	-107 <= k <= 107
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    let result = 0;
	let map = new Map();
	map.set(0, 1);
	let sum = 0;
	for (let i = 0; i < nums.length; i++) {
		sum += nums[i];
		if (map.has(sum - k)) {
			result += map.get(sum - k);
		}
		map.set(sum, map.get(sum) ? map.get(sum) + 1 : 1);
	}
	return result;
};