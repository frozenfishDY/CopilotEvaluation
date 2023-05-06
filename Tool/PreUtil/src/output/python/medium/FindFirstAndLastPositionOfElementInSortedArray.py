#https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
#If target is not found in the array, return [-1, -1].
#You must write an algorithm with O(log n) runtime complexity.


class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return [-1, -1]
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        if nums[left] != target:
            return [-1, -1]
        start = left
        right = len(nums) - 1
        while left < right:
            mid = (left + right) // 2 + 1
            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid
        return [start, right]
        

    