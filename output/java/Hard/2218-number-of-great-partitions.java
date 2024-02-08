/**https://leetcode.com/problems/number-of-great-partitions/ */
//You are given an array nums consisting of positive integers and an integer k.
//Partition the array into two ordered groups such that each element is in exactly one group. A partition is called great if the sum of elements of each group is greater than or equal to k.
//Return the number of distinct great partitions. Since the answer may be too large, return it modulo 109 + 7.
//Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.


class NumberOfGreatPartitions {
    public int countPartitions(int[] nums, int k) {
        int n = nums.length;
        int[] preSum = new int[n + 1];
        for(int i = 1; i <= n; i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int[][] dp = new int[n + 1][n + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = -1;
            }
        }
        return dfs(n, k, preSum, 0, 0, dp);
        
    }
}
     
    