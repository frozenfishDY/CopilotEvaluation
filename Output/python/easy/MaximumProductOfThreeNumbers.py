#https://leetcode.com/problems/maximum-product-of-three-numbers/
#Given an integer array nums, find three numbers whose product is maximum and return the maximum product.


class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """      
        nums.sort()
        return max(nums[-1]*nums[-2]*nums[-3],nums[0]*nums[1]*nums[-1])
        

    