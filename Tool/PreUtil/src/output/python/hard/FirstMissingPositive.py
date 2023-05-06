#https://leetcode.com/problems/first-missing-positive/
#Given an unsorted integer array nums, return the smallest missing positive integer.
#You must implement an algorithm that runs in O(n) time and uses constant extra space.


class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 1
        if len(nums)==1:
            if nums[0]==1:
                return 2
            else:
                return 1
        nums.sort()
        if nums[0]>1:
            return 1
        for i in range(1,len(nums)):
            if nums[i]>0 and nums[i]-nums[i-1]>1:
                return nums[i-1]+1
        return nums[-1]+1
        
    