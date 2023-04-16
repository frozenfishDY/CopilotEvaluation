#https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/
#Given an integer array nums, return the number of AND triples.
#An AND triple is a triple of indices (i, j, k) such that:
#0 <= i < nums.length
#0 <= j < nums.length
#0 <= k < nums.length
#nums[i] & nums[j] & nums[k] == 0, where & represents the bitwise-AND operator.


class Solution(object):
    def countTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums)==1:
            return 0
        if len(nums)==2:
            return 0
        result = 0
        for i in range(len(nums)):
            result += self.countTriplets(nums[:i]+nums[i+1:])
        return result
        
        
    