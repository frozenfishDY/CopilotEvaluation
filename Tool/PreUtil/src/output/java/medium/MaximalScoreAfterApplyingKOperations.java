/**https://leetcode.com/problems/maximal-score-after-applying-k-operations/ */
//You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
//In one operation:
//choose an index i such that 0 <= i < nums.length,
//increase your score by nums[i], and
//replace nums[i] with ceil(nums[i] / 3).
//Return the maximum possible score you can attain after applying exactly k operations.
//The ceiling function ceil(val) is the least integer greater than or equal to val.


class MaximalScoreAfterApplyingKOperations {
    public long maxKelements(int[] nums, int k) {
        int n = nums.length;
        long[] dp = new long[n + 1];
        for(int i = 0; i < n; i++){
            dp[i + 1] = dp[i] + nums[i];
        }
        long res = 0;
        for(int i = 0; i <= k; i++){
            if(i <= n && k - i <= n){
                res = Math.max(res, maxKelements(dp, i) + maxKelements(dp, k - i));
            }
        }
        return res;
        
        
        
    }
}

    