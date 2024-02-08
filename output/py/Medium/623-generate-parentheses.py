#https://leetcode.com/problems/generate-parentheses/
#Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
# 


class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """  
        res = []
        self.dfs(n, n, "", res)
        return res
        

    