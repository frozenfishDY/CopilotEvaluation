#https://leetcode.com/problems/minimum-size-subarray-sum/
#Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """       
        res = len(nums)+1
        left = 0
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            while sum >= target:
                res = min(res, i+1-left)
                sum -= nums[left]
                left += 1
        return 0 if res == len(nums)+1 else res

        

    