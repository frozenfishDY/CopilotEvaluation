#https://leetcode.com/problems/ipo/
#Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
#You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
#Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
#Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
#The answer is guaranteed to fit in a 32-bit signed integer.


class Solution(object):
    def findMaximizedCapital(self, k, w, profits, capital):
        """
        :type k: int
        :type w: int
        :type profits: List[int]
        :type capital: List[int]
        :rtype: int
        """     
        if not profits or not capital:
            return 0
        if k == 0:
            return w
        if len(profits) != len(capital):
            return 0
        if w == 0:
            return 0
        if k == 1:
            return w + max(profits)
        if k == len(profits):
            return w + sum(profits)
        if k > len(profits):
            return w + sum(profits)
        if k < len(profits):
            return w + sum(profits[:k])
        return w

        
        
    