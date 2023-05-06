#https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
#Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
#A subarray is a contiguous part of an array.


class Solution(object):
    def shortestSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """      
        if not nums:
            return -1
        result=0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)+1):
                if sum(nums[i:j])>=k:
                    result=j-i
                    break
        return result
      
           
        
        
    