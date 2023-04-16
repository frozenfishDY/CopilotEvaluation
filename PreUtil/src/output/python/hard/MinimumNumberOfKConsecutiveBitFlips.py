#https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
#You are given a binary array nums and an integer k.
#A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
#Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.
#A subarray is a contiguous part of an array.


class Solution(object):
    def minKBitFlips(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums)==1:
            return 0
        if len(nums)==2:
            return 0
        result = 0
        for i in range(len(nums)):
            result += self.minKBitFlips(nums[:i]+nums[i+1:],k)
        return result
        
        
    