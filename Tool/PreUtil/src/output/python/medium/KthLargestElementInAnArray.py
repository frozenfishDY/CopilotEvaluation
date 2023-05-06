#https://leetcode.com/problems/kth-largest-element-in-an-array/
#Given an integer array nums and an integer k, return the kth largest element in the array.
#Note that it is the kth largest element in the sorted order, not the kth distinct element.
#You must solve it in O(n) time complexity.


class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return sorted(nums,reverse=True)[k-1]
        

    