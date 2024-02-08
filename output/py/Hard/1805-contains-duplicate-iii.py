#https://leetcode.com/problems/contains-duplicate-iii/
#You are given an integer array nums and two integers indexDiff and valueDiff.
#Find a pair of indices (i, j) such that:
#i != j,
#abs(i - j) <= indexDiff.
#abs(nums[i] - nums[j]) <= valueDiff, and
#Return true if such pair exists or false otherwise.


class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, indexDiff, valueDiff):
        """
        :type nums: List[int]
        :type indexDiff: int
        :type valueDiff: int
        :rtype: bool
        """        
        if not nums:
            return False
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if abs(i-j) <= indexDiff and abs(nums[i]-nums[j]) <= valueDiff:
                    return True
        return False


        
        
    