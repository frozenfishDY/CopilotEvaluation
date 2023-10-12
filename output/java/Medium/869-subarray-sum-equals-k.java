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
class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int[] preSum = new int[n + 1];
        preSum[0] = 0;
        int result = 0;
        for (int i = 1; i <= n; i++) {
            preSum[i] = nums[i - 1] + preSum[i - 1];
            for (int j = 0; j < i; j++) {
                if (preSum[i] - preSum[j] == k) {
                    result++;
                }
            }
        }
        return result;
    }
}