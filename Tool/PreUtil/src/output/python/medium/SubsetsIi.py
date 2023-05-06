#https://leetcode.com/problems/subsets-ii/
#Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
#The solution set must not contain duplicate subsets. Return the solution in any order.


class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        self.dfs(nums, 0, [], res)
        return res
        

    