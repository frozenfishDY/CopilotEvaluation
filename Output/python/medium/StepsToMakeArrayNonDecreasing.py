#https://leetcode.com/problems/steps-to-make-array-non-decreasing/
#You are given a 0-indexed integer array nums. In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.
#Return the number of steps performed until nums becomes a non-decreasing array.


class Solution(object):
    def totalSteps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """                 
        return self.totalStepsFromIndex(nums,0)
       
    