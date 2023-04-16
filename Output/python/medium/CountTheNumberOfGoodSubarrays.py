#https://leetcode.com/problems/count-the-number-of-good-subarrays/
#Given an integer array nums and an integer k, return the number of good subarrays of nums.
#A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
#A subarray is a contiguous non-empty sequence of elements within an array.


class Solution(object):
    def countGood(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res = 0
        dp = [0]*len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] == nums[j]:
                    dp[i] += 1
                    if dp[i] >= k:
                        res += 1
        return res
        

    