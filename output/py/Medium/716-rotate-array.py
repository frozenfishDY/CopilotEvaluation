#https://leetcode.com/problems/rotate-array/
#Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """     
        n = len(nums)
        k = k % n
        nums[:] = nums[n-k:] + nums[:n-k]
        return nums

        

    