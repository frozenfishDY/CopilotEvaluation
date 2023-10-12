/**https://leetcode.com/problems/largest-number/ */
//Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//Since the result may be very large, so you need to return a string instead of an integer.
// 
//Example 1:
//Input: nums = [10,2]
//Output: "210"
//Example 2:
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//Constraints:
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    let len = nums.length;
    if (len === 1) return nums[0].toString();
    if (len === 2) {
        let a = nums[0].toString();
        let b = nums[1].toString();
        let ab = a + b;
        let ba = b + a;
        return ab > ba ? ab : ba;
    }
    nums.sort((a, b) => {
        let ab = a.toString() + b.toString();
        let ba = b.toString() + a.toString();
        return ab > ba ? -1 : 1;
    });
    if (nums[0] === 0) return "0";
    return nums.join("");
};