/**https://leetcode.com/problems/longest-square-streak-in-an-array/ */
//You are given an integer array nums. A subsequence of nums is called a square streak if:
//The length of the subsequence is at least 2, and
//after sorting the subsequence, each element (except the first element) is the square of the previous number.
//Return the length of the longest square streak in nums, or return -1 if there is no square streak.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


class LongestSquareStreakInAnArray {
    public int longestSquareStreak(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] == nums[j] * nums[j]){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    res = Math.max(res, dp[i]);
                }
            }
        }
        return res == 0 ? -1 : res + 1;
        
    }
}

    