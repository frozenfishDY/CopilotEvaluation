/**https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/ */
//A split of an integer array is good if:
//	The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
//	The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
//Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [1,1,1]
//Output: 1
//Explanation: The only good way to split nums is [1] [1] [1].
//Example 2:
//Input: nums = [1,2,2,2,5,0]
//Output: 3
//Explanation: There are three good ways of splitting nums:
//[1] [2] [2,2,5,0]
//[1] [2,2] [2,5,0]
//[1,2] [2,2] [5,0]
//Example 3:
//Input: nums = [3,2,1]
//Output: 0
//Explanation: There is no good way to split nums.
// 
//Constraints:
//	3 <= nums.length <= 105
//	0 <= nums[i] <= 104
/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplit = function(nums) {
    let mod = 10 ** 9 + 7;
    let res = 0;
    let l = 0;
    let r = 0;
    let sum = 0;
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
    }
    let left = 0;
    let right = sum;
    for (let i = 0; i < nums.length - 2; i++) {
        left += nums[i];
        right -= nums[i];
        l = i + 1;
        r = i + 1;
        while (l < nums.length - 1 && left > sum - left - right) {
            left -= nums[l++];
        }
        while (r < nums.length - 1 && right >= left) {
            right -= nums[r++];
        }
        if (left <= right) {
            res = (res + r - l) % mod;
        }
    }
    return res;
};