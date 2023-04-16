/**https://leetcode.com/problems/number-of-zero-filled-subarrays/ */
//Given an integer array nums, return the number of subarrays filled with 0.
//A subarray is a contiguous non-empty sequence of elements within an array.


class NumberOfZeroFilledSubarrays {
    public long zeroFilledSubarray(int[] nums) {
        int n = nums.length;
        long[][] dp = new long[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }
        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                dp[i][j] = dp[i][j-1] & nums[j];
            }
        }
        long count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
        
    }
}
     
    