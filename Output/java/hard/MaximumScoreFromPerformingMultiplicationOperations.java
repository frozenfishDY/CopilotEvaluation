/**https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/ */
//You are given two 0-indexed integer arrays nums and multipliers of size n and m respectively, where n >= m.
//You begin with a score of 0. You want to perform exactly m operations. On the ith operation (0-indexed) you will:
//Choose one integer x from either the start or the end of the array nums.
//Add multipliers[i] * x to your score.
//Note that multipliers[0] corresponds to the first operation, multipliers[1] to the second operation, and so on.
//Remove x from nums.
//Return the maximum score after performing m operations.


class MaximumScoreFromPerformingMultiplicationOperations {
    public int maximumScore(int[] nums, int[] multipliers) {
        int n = nums.length;
        int m = multipliers.length;
        int[][] dp = new int[m + 1][m + 1];
        for(int i = 1; i <= m; i++){
            dp[i][0] = dp[i - 1][0] + multipliers[i - 1] * nums[i - 1];
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = Math.max(dp[i - 1][j - 1] + multipliers[i - 1] * nums[j - 1], dp[i - 1][j] + multipliers[i - 1] * nums[n - i + j - 1]);
            }
        }
        int res = Integer.MIN_VALUE;
        for(int i = 0; i <= m; i++){
            res = Math.max(res, dp[m][i]);
        }
        return res;
        
    }
}
     
    