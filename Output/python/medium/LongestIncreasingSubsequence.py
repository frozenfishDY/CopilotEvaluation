#https://leetcode.com/problems/longest-increasing-subsequence/
#Given an integer array nums, return the length of the longest strictly increasing subsequence.


class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        dp = [1]*len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i],dp[j]+1)
            res = max(res,dp[i])
        return res
        

    