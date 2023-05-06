#https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
#Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
#The test cases are generated so that the answer will fit in a 32-bit integer.


class Solution(object):
    def numSubarrayBoundedMax(self, nums, left, right):
        """
        :type nums: List[int]
        :type left: int
        :type right: int
        :rtype: int
        """
        res = 0
        for i in range(len(nums)):
            for j in range(i,len(nums)):
                if max(nums[i:j+1]) >= left and max(nums[i:j+1]) <= right:
                    res += 1
        return res
        

    