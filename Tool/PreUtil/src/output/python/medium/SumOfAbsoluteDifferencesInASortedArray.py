#https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
#You are given an integer array nums sorted in non-decreasing order.
#Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.
#In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).


class Solution(object):
    def getSumAbsoluteDifferences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """       
        result=[]
        for i in range(len(nums)):
            result.append(sum([abs(nums[i]-nums[j]) for j in range(len(nums)) if i!=j]))
        return result
        

    