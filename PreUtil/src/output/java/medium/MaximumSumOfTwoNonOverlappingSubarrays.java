/**https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/ */
//Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
//The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.
//A subarray is a contiguous part of an array.


class MaximumSumOfTwoNonOverlappingSubarrays {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        int max = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1] + nums[i - 1];
            if(i >= firstLen){
                max = Math.max(max, dp[i] - dp[i - firstLen]);
                if(i >= firstLen + secondLen){
                    dp[i] = Math.max(dp[i], dp[i - secondLen] + max);
                }
            }
            if(i >= firstLen + secondLen){
                max = Math.max(max, dp[i] - dp[i - secondLen] - dp[i - firstLen - secondLen]);
            }
        }
        return dp[n];
        
        
    }
}

    