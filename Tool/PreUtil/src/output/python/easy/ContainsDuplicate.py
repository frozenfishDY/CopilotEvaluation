#https://leetcode.com/problems/contains-duplicate/
#Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.


class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """ 
        res=[]
        for i in range(len(nums)):
            if nums[i] in res:
                return True
            else:
                res.append(nums[i])
        return False

    