/**https://leetcode.com/problems/partition-equal-subset-sum/ */
//Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


class PartitionEqualSubsetSum {
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(sum % 2 == 1){
            return false;
        }
        sum /= 2;
        boolean[][] dp = new boolean[n + 1][sum + 1];
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(j >= nums[i - 1]){
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
        
        
        
    }
}

    