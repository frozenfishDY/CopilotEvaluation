#https://leetcode.com/problems/contains-duplicate-ii/
#Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.


class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """ 
        res=[]
        for i in range(len(nums)):
            if nums[i] in res:
                return True
            else:
                res.append(nums[i])
        return False

    