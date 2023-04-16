#https://leetcode.com/problems/subarrays-with-k-different-integers/
#Given an integer array nums and an integer k, return the number of good subarrays of nums.
#A good array is an array where the number of different integers in that array is exactly k.
#For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
#A subarray is a contiguous part of an array.


class Solution(object):
    def subarraysWithKDistinct(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """       
        if not nums:
            return 0
        if len(nums)==1:
            return 1
        if len(nums)==2:
            return 2
        result = 0
        for i in range(len(nums)):
            result += self.subarraysWithKDistinct(nums[:i]+nums[i+1:],k)
        return result
        
        
    