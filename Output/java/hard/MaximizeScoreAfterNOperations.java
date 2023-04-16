/**https://leetcode.com/problems/maximize-score-after-n-operations/ */
//You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
//In the ith operation (1-indexed), you will:
//Choose two elements, x and y.
//Receive a score of i * gcd(x, y).
//Remove x and y from nums.
//Return the maximum score you can receive after performing n operations.
//The function gcd(x, y) is the greatest common divisor of x and y.


class MaximizeScoreAfterNOperations {
    public int maxScore(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int[][] memo = new int[n][1 << n];
        return dfs(0, 0, dp, memo);
        
    }
}
     
    