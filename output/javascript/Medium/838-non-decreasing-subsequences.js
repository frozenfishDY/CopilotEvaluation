/**https://leetcode.com/problems/non-decreasing-subsequences/ */
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//Example 2:
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//Constraints:
//	1 <= nums.length <= 15
//	-100 <= nums[i] <= 100
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var findSubsequences = function(nums) {
    let result = [];
    let current = [];
    let visited = new Set();
    dfs(nums, 0, current, visited, result);
    return result;
};
function dfs(nums, index, current, visited, result) {
    if (current.length > 1) {
        result.push(current.slice());
    }
    for (let i = index; i < nums.length; i++) {
        if (visited.has(i) || (current.length && nums[i] < current[current.length - 1])) {
            continue;
        }
        visited.add(i);
        current.push(nums[i]);
        dfs(nums, i + 1, current, visited, result);
        current.pop();
        visited.delete(i);
    }
}