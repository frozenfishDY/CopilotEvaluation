#https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#Given an integer array nums, return the number of longest increasing subsequences.
#Notice that the sequence has to be strictly increasing.


class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j+1,len(nums)):
                    if nums[i] < nums[k] < nums[j]:
                        res += 1
        return res
        

    