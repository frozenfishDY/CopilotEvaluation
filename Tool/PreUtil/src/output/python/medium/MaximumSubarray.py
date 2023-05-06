#https://leetcode.com/problems/maximum-subarray/
#Given an integer array nums, find the subarray with the largest sum, and return its sum.


class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """ 
        max_sum = nums[0]
        for i in range(1, len(nums)):
            if nums[i - 1] > 0:
                nums[i] += nums[i - 1]
            max_sum = max(max_sum, nums[i])
        return max_sum
        

    