/**https://leetcode.com/problems/longest-increasing-subsequence/ */
//Given an integer array nums, return the length of the longest strictly increasing subsequence.


class LongestIncreasingSubsequence {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int res = 0;
        for(int i = 0; i < nums.length; i++){
            int left = 0;
            int right = res;
            while(left < right){
                int mid = left + (right - left) / 2;
                if(dp[mid] < nums[i]){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            dp[left] = nums[i];
            if(left == res){
                res++;
            }
        }
        return res;
        
    }
}

    