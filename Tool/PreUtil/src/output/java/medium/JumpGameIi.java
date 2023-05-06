/**https://leetcode.com/problems/jump-game-ii/ */
//You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
//Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
//0 <= j <= nums[i] and
//i + j < n
//Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].


class JumpGameIi {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= nums[i]; j++){
                if(i + j < n){
                    dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1];
        
    }
}

    