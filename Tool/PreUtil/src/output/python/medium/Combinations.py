#https://leetcode.com/problems/combinations/
#Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
#You may return the answer in any order.


class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """ 
        res = []
        self.dfs(range(1, n + 1), k, 0, [], res)
        return res
        

    