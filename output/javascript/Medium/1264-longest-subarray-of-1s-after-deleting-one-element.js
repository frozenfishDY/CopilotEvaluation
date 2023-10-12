/**https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/ */
//Given a binary array nums, you should delete one element from it.
//Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
// 
//Example 1:
//Input: nums = [1,1,0,1]
//Output: 3
//Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
//Example 2:
//Input: nums = [0,1,1,1,0,1,1,0,1]
//Output: 5
//Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
//Example 3:
//Input: nums = [1,1,1]
//Output: 2
//Explanation: You must delete one element.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSubarray = function(nums) {
    let result = 0;
    let left = 0;
    let right = 0;
    let count = 0;
    while (right < nums.length) {
        if (nums[right] === 0) {
            count++;
        }
        while (count > 1) {
            if (nums[left] === 0) {
                count--;
            }
            left++;
        }
        result = Math.max(result, right - left);
        right++;
    }
    return result;  
};