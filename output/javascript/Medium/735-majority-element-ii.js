/**https://leetcode.com/problems/majority-element-ii/ */
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// 
//Example 1:
//Input: nums = [3,2,3]
//Output: [3]
//Example 2:
//Input: nums = [1]
//Output: [1]
//Example 3:
//Input: nums = [1,2]
//Output: [1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-109 <= nums[i] <= 109
// 
//Follow up: Could you solve the problem in linear time and in O(1) space?
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    let len = nums.length;
    if (len === 1) return nums;
    let result = [];
    let max = Math.floor(len / 3);
    let map = new Map();
    for (let i = 0; i < len; i++) {
        let key = nums[i];
        if (map.has(key)) {
            let value = map.get(key);
            value++;
            if (value > max) {
                result.push(key);
                map.delete(key);
            } else {
                map.set(key, value);
            }
        } else {
            map.set(key, 1);
        }
    }
    return result;
};