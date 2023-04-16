#https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
#You are given an array nums consisting of positive integers.
#You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
#Return the number of distinct integers in the final array.


class Solution(object):
    def countDistinctIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """ 
        # 1. find the number of distinct integers in the final array
        # 2. return the number of distinct integers in the final array
        # 1. find the number of distinct integers in the final array
        # 2. return the number of distinct integers in the final array
        return self.countDistinctIntegersFromIndex(nums, 0, set())
       
        
    