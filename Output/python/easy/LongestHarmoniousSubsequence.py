#https://leetcode.com/problems/longest-harmonious-subsequence/
#We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
#Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
#A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.


class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """       
        nums.sort()
        max_length=0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[j]-nums[i]==1:
                    max_length=max(max_length,j-i+1)
        return max_length
        

    