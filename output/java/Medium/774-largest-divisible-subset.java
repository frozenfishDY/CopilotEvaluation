/**https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//	answer[i] % answer[j] == 0, or
//	answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [1,2]
//Explanation: [1,3] is also accepted.
//Example 2:
//Input: nums = [1,2,4,8]
//Output: [1,2,4,8]
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 109
//	All the integers in nums are unique.
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<Integer> result = new ArrayList<>();
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int max = 1;
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            int maxVal = 0;
            while (j >= 0) {
                if (nums[i] % nums[j] == 0) {
                    maxVal = Math.max(maxVal, dp[j]);
                }
                j--;
            }
            dp[i] = maxVal + 1;
            if (dp[i] > max) {
                max = dp[i];
                maxIndex = i;
            }
        }
        int val = nums[maxIndex];
        int count = dp[maxIndex];
        for (int i = maxIndex; i >= 0; i--) {
            if (val % nums[i] == 0 && dp[i] == count) {
                result.add(nums[i]);
                val = nums[i];
                count--;
            }
        }
        return result;
    }
}