#https://leetcode.com/problems/largest-component-size-by-common-factor/
#You are given an integer array of unique positive integers nums. Consider the following graph:
#There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
#There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
#Return the size of the largest connected component in the graph.


class Solution(object):
    def largestComponentSize(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums)==1:
            return 1
        if len(nums)==2:
            return 2
        result = 0
        for i in range(len(nums)):
            result = max(result,self.largestComponentSize(nums[:i]+nums[i+1:]))
        return result
        
        
    