#https://leetcode.com/problems/third-maximum-number/
#Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.


class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """ 
        if len(nums)==0:
            return 0
        if len(nums)==1:
            return nums[0]
        if len(nums)==2:
            return max(nums)
        nums=sorted(set(nums))
        if len(nums)<3:
            return max(nums)
        return nums[len(nums)-3]

    