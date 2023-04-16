/**https://leetcode.com/problems/largest-sum-of-averages/ */
//You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
//Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
//Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.


class LargestSumOfAverages {
    public double largestSumOfAverages(int[] nums, int k) {
        int n = nums.length;
        double[] sum = new double[n + 1];
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        double[] dp = new double[n];
        for(int i = 0; i < n; i++){
            dp[i] = (sum[n] - sum[i]) / (n - i);
        }
        for(int i = 0; i < k - 1; i++){
            for(int j = 0; j < n; j++){
                for(int l = j + 1; l < n; l++){
                    dp[j] = Math.max(dp[j], (sum[l] - sum[j]) / (l - j) + dp[l]);
                }
            }
        }
        return dp[0];
        
        
    }
}

    