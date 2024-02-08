/**https://leetcode.com/problems/partition-to-k-equal-sum-subsets/ */
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
// 
//Example 1:
//Input: nums = [4,3,2,3,5,2,1], k = 4
//Output: true
//Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//Example 2:
//Input: nums = [1,2,3,4], k = 3
//Output: false
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	1 <= nums[i] <= 104
//	The frequency of each element is in the range [1, 4].
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var canPartitionKSubsets = function(nums, k) {
    const sum = nums.reduce((a, b) => a + b);
    if (sum % k !== 0) {
        return false;
    }
    const target = sum / k;
    const visited = new Array(nums.length).fill(false);
    const canPartition = (start, currentSum, currentK) => {
        if (currentK === 0) {
            return true;
        }
        if (currentSum === target) {
            return canPartition(0, 0, currentK - 1);
        }
        for (let i = start; i < nums.length; i++) {
            if (!visited[i] && currentSum + nums[i] <= target) {
                visited[i] = true;
                if (canPartition(i + 1, currentSum + nums[i], currentK)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
    return canPartition(0, 0, k);
};