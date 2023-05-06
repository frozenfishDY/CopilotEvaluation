#https://leetcode.com/problems/maximum-product-subarray/
#Given an integer array nums, find a subarray that has the largest product, and return the product.
#The test cases are generated so that the answer will fit in a 32-bit integer.


class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = nums[0]
        imax = res
        imin = res
        for i in range(1,len(nums)):
            if nums[i] < 0:
                imax,imin = imin,imax
            imax = max(nums[i],imax*nums[i])
            imin = min(nums[i],imin*nums[i])
            res = max(res,imax)
        return res
        

    