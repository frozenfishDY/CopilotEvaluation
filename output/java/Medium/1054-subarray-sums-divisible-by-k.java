/**https://leetcode.com/problems/subarray-sums-divisible-by-k/ */
//Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
//A subarray is a contiguous part of an array.


class SubarraySumsDivisibleByK {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        int count = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1] + nums[i - 1];
            if(dp[i] % k == 0){
                count++;
            }
            for(int j = i - 1; j >= 0; j--){
                if((dp[i] - dp[j]) % k == 0){
                    count++;
                }
            }
        }
        return count;
        
    }
}

    