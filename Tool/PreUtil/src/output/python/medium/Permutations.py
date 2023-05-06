#https://leetcode.com/problems/permutations/
#Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """ 
        res = []
        self.dfs(nums, [], res)
        return res
         
            
           

        

    