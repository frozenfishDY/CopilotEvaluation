/**https://leetcode.com/problems/longest-arithmetic-subsequence/ */
//Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
//Note that:
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).


class LongestArithmeticSubsequence {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][20001];
        int max = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int diff = nums[j] - nums[i] + 10000;
                dp[j][diff] = Math.max(dp[j][diff], dp[i][diff] + 1);
                max = Math.max(max, dp[j][diff]);
            }
        }
        return max + 1;
        
        
    }
}

    