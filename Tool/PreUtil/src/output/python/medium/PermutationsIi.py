#https://leetcode.com/problems/permutations-ii/
#Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.


class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """ 
        res = []
        nums.sort()
        self.dfs(nums, [], res)
        return res
        

    