#https://leetcode.com/problems/minimum-average-difference/
#You are given a 0-indexed integer array nums of length n.
#The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.
#Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.
#Note:
#The absolute difference of two numbers is the absolute value of their difference.
#The average of n elements is the sum of the n elements divided (integer division) by n.
#The average of 0 elements is considered to be 0.


class Solution(object):
    def minimumAverageDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in range(len(nums)):
            if nums[i] != target[i]:
                for j in range(i+1, len(nums)):
                    if nums[j] == target[i]:
                        nums[i], nums[j] = nums[j], nums[i]
                        result += 1
                        break
        return result
        
    