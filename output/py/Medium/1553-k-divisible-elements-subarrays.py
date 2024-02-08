#https://leetcode.com/problems/k-divisible-elements-subarrays/
#Given an integer array nums and two integers k and p, return the number of distinct subarrays which have at most k elements divisible by p.
#Two arrays nums1 and nums2 are said to be distinct if:
#They are of different lengths, or
#There exists at least one index i where nums1[i] != nums2[i].
#A subarray is defined as a non-empty contiguous sequence of elements in an array.


class Solution(object):
    def countDistinct(self, nums, k, p):
        """
        :type nums: List[int]
        :type k: int
        :type p: int
        :rtype: int
        """
        # 1. find the number of subarrays with at most k elements divisible by p
        # 2. find the number of subarrays with at most k-1 elements divisible by p
        # 3. return the difference
        return self.countDistinctFromIndex(nums, k, p, 0, 0, 0)
        
    