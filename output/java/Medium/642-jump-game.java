/**https://leetcode.com/problems/jump-game/ */
//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
//Return true if you can reach the last index, or false otherwise.


class JumpGame {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        boolean[] dp = new boolean[n];
        dp[0] = true;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= nums[i]; j++){
                if(i + j < n){
                    dp[i + j] = dp[i + j] || dp[i];
                }
            }
        }
        return dp[n - 1];
        
    }
}

    