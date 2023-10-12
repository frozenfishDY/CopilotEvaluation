/**https://leetcode.com/problems/target-sum/ */
//You are given an integer array nums and an integer target.
//You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
//	For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
//Return the number of different expressions that you can build, which evaluates to target.
// 
//Example 1:
//Input: nums = [1,1,1,1,1], target = 3
//Output: 5
//Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
//Example 2:
//Input: nums = [1], target = 1
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 20
//	0 <= nums[i] <= 1000
//	0 <= sum(nums[i]) <= 1000
//	-1000 <= target <= 1000
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int[][] dp = new int[n][2 * sum + 1];
        dp[0][sum + nums[0]] = 1;
        dp[0][sum - nums[0]] += 1;
        for (int i = 1; i < n; i++) {
            for (int j = -sum; j <= sum; j++) {
                if (dp[i - 1][sum + j] > 0) {
                    dp[i][sum + j + nums[i]] += dp[i - 1][sum + j];
                    dp[i][sum + j - nums[i]] += dp[i - 1][sum + j];
                }
            }
        }
        return target > sum ? 0 : dp[n - 1][sum + target];
    }
}