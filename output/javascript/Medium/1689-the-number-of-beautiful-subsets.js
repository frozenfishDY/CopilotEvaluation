/**https://leetcode.com/problems/the-number-of-beautiful-subsets/ */
//You are given an array nums of positive integers and a positive integer k.
//A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
//Return the number of non-empty beautiful subsets of the array nums.
//A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
// 
//Example 1:
//Input: nums = [2,4,6], k = 2
//Output: 4
//Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
//It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
//Example 2:
//Input: nums = [1], k = 1
//Output: 1
//Explanation: The beautiful subset of the array nums is [1].
//It can be proved that there is only 1 beautiful subset in the array [1].
// 
//Constraints:
//	1 <= nums.length <= 20
//	1 <= nums[i], k <= 1000
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var beautifulSubsets = function(nums, k) {
    let count = 0;
    let set = new Set();
    for (let i = 0; i < nums.length; i++) {
        let val = nums[i];
        if (val === 1) {
            count++;
        } else {
            let isBeautiful = true;
            for (let j = 2; j <= val; j++) {
                let diff = Math.abs(val - j);
                if (diff === k) {
                    isBeautiful = false;
                    break;
                }
            }
            if (isBeautiful) {
                count++;
            } else {
                set.add(val);
            }
        }
    }
    let arr = Array.from(set);
    let len = arr.length;
    for (let i = 0; i < len; i++) {
        let val = arr[i];
        let isBeautiful = true;
        for (let j = i+1; j < len; j++) {
            let diff = Math.abs(val - arr[j]);
            if (diff === k) {
                isBeautiful = false;
                break;
            }
        }
        if (isBeautiful) {
            count++;
        }
    }
    return count;
};