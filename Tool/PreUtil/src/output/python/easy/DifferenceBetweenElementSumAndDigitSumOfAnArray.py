#https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
#You are given a positive integer array nums.
#The element sum is the sum of all the elements in nums.
#The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
#Return the absolute difference between the element sum and digit sum of nums.
#Note that the absolute difference between two integers x and y is defined as |x - y|.


class Solution(object):
    def differenceOfSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """    
        element_sum=0
        digit_sum=0
        for i in nums:
            element_sum+=i
            while i>0:
                digit_sum+=i%10
                i=i//10
        return abs(element_sum-digit_sum)

    