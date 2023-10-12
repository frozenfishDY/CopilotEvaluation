/**https://leetcode.com/problems/maximum-product-difference-between-two-pairs/ */
//The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d)._x000D_
//_x000D_
//_x000D_
//	For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16._x000D_
//_x000D_
//_x000D_
//Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized._x000D_
//_x000D_
//Return the maximum such product difference._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: nums = [5,6,2,7,4]_x000D_
//Output: 34_x000D_
//Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4)._x000D_
//The product difference is (6 * 7) - (2 * 4) = 34._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: nums = [4,2,5,9,7,4,8]_x000D_
//Output: 64_x000D_
//Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4)._x000D_
//The product difference is (9 * 8) - (2 * 4) = 64._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	4 <= nums.length <= 104_x000D_
//	1 <= nums[i] <= 104_x000D_
/**_x000D_
 * @param {number[]} nums_x000D_
 * @return {number}_x000D_
 */_x000D_
var maxProductDifference = function(nums) {  
    let max1 = Math.max(...nums);    let index1 = nums.indexOf(max1);    nums.splice(index1, 1);    let max2 = Math.max(...nums);    let index2 = nums.indexOf(max2);    nums.splice(index2, 1);    let min1 = Math.min(...nums);    let index3 = nums.indexOf(min1);    nums.splice(index3, 1);    let min2 = Math.min(...nums);    let index4 = nums.indexOf(min2);    nums.splice(index4, 1);    return max1 * max2 - min1 * min2;

};