#https://leetcode.com/problems/maximum-width-ramp/
#A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
#Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.


class Solution(object):
    def maxWidthRamp(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stack = []
        for i, num in enumerate(nums):
            if not stack or num < nums[stack[-1]]:
                stack.append(i)
        res = 0
        for i in range(len(nums) - 1, -1, -1):
            while stack and nums[i] >= nums[stack[-1]]:
                res = max(res, i - stack.pop())
        return res
        

    