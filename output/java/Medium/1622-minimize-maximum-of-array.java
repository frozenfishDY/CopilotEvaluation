/**https://leetcode.com/problems/minimize-maximum-of-array/ */
//You are given a 0-indexed array nums comprising of n non-negative integers.
//In one operation, you must:
//Choose an integer i such that 1 <= i < n and nums[i] > 0.
//Decrease nums[i] by 1.
//Increase nums[i - 1] by 1.
//Return the minimum possible value of the maximum integer of nums after performing any number of operations.


class MinimizeMaximumOfArray {
    public int minimizeArrayValue(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                dp[i][j] = Math.min(dp[i][j-1], nums[j]);
            }
        }
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                min = Math.min(min, Math.max(dp[i][j], j-i+1));
            }
        }
        return min;
        
    }
}
     
    