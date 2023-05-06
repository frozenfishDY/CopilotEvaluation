#https://leetcode.com/problems/split-array-largest-sum/
#Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
#Return the minimized largest sum of the split.
#A subarray is a contiguous part of the array.


class Solution(object):
    def splitArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """      
        if not nums:
            return 0
        if k==1:
            return sum(nums)
        if k==len(nums):
            return max(nums)
        result = []
        for i in range(len(nums)-k+1):
            result.append(max(nums[i:i+k]))
        return min(result)
        
        
    