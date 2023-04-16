#https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
#Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
#In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
#Note that 0 is neither positive nor negative.


class Solution(object):
    def maximumCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """   
        pos=0
        neg=0
        for i in nums:
            if i>0:
                pos+=1
            elif i<0:
                neg+=1
        return max(pos,neg)

    