#https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
#Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
#The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.
#A subarray is a contiguous part of an array.


class Solution(object):
    def maxSumTwoNoOverlap(self, nums, firstLen, secondLen):
        """
        :type nums: List[int]
        :type firstLen: int
        :type secondLen: int
        :rtype: int
        """
        res = 0
        dp = [0]*(len(nums)+1)
        for i in range(1,len(nums)+1):
            dp[i] = dp[i-1]+nums[i-1]
        for i in range(firstLen,len(nums)+1):
            res = max(res,dp[i]-dp[i-firstLen]+self.maxSum(dp,i-firstLen,secondLen))
            res = max(res,dp[i]-dp[i-firstLen]+self.maxSum(dp,i,secondLen))
        return res
        

    