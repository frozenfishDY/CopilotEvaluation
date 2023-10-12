/**https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/ */
//A swap is defined as taking two distinct positions in an array and swapping the values in them.
//A circular array is defined as an array where we consider the first element and the last element to be adjacent.
//Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.
// 
//Example 1:
//Input: nums = [0,1,0,1,1,0,0]
//Output: 1
//Explanation: Here are a few of the ways to group all the 1's together:
//[0,0,1,1,1,0,0] using 1 swap.
//[0,1,1,1,0,0,0] using 1 swap.
//[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
//There is no way to group all 1's together with 0 swaps.
//Thus, the minimum number of swaps required is 1.
//Example 2:
//Input: nums = [0,1,1,1,0,0,1,1,0]
//Output: 2
//Explanation: Here are a few of the ways to group all the 1's together:
//[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
//[1,1,1,1,1,0,0,0,0] using 2 swaps.
//There is no way to group all 1's together with 0 or 1 swaps.
//Thus, the minimum number of swaps required is 2.
//Example 3:
//Input: nums = [1,1,0,0,1]
//Output: 0
//Explanation: All the 1's are already grouped together due to the circular property of the array.
//Thus, the minimum number of swaps required is 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is either 0 or 1.
/**
 * @param {number[]} nums
 * @return {number}
 */
var minSwaps = function(nums) {
    let n = nums.length;
    let res = Number.MAX_SAFE_INTEGER;
    let sum = 0;
    let count = 0;
    let left = 0;
    let right = 0;
    for (let i = 0; i < n; i++) {
        sum += nums[i];
    }
    if (sum <= 1) {
        return 0;
    }
    for (let i = 0; i < n; i++) {
        if (nums[i] === 1) {
            count++;
        }
        if (i === sum - 1) {
            right = count;
        }
    }
    for (let i = 0; i < sum - 1; i++) {
        if (nums[i] === 1) {
            left++;
        }
        if (nums[i + sum - 1] === 1) {
            right++;
        }
        res = Math.min(res, sum - (right - left));
    }
    return res;
};