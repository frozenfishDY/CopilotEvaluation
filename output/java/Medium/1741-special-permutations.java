/**https://leetcode.com/problems/special-permutations/ */
//You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:
//	For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
//Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [2,3,6]
//Output: 2
//Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
//Example 2:
//Input: nums = [1,4,3]
//Output: 2
//Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
// 
//Constraints:
//	2 <= nums.length <= 14
//	1 <= nums[i] <= 109
class Solution {
    public int specialPerm(int[] nums) {
        int n = nums.length;
        int[] dp = new int[1 << n];
        dp[0] = 1;
        for (int i = 1; i < 1 << n; i++) {
            int count = 0;
            int index = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    index = j;
                    count++;
                }
            }
            if (count == 1) {
                dp[i] = 1;
            } else {
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) > 0 && (nums[index] % nums[j] == 0 || nums[j] % nums[index] == 0)) {
                        dp[i] += dp[i ^ (1 << index)];
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
}