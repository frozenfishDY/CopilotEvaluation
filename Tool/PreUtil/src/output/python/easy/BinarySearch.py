#https://leetcode.com/problems/binary-search/
#Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
#You must write an algorithm with O(log n) runtime complexity.


class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """       
        if target in nums:
            return nums.index(target)
        else:
            return -1
        

    