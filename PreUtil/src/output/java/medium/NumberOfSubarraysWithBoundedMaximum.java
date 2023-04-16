/**https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/ */
//Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
//The test cases are generated so that the answer will fit in a 32-bit integer.


class NumberOfSubarraysWithBoundedMaximum {
    public int numSubarrayBoundedMax(int[] nums, int left, int right) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(nums[i - 1] >= left && nums[i - 1] <= right){
                dp[i] = i;
                count += dp[i];
            }else if(nums[i - 1] < left){
                dp[i] = dp[i - 1];
                count += dp[i];
            }
        }
        return count;
        
    }
}

    