#https://leetcode.com/problems/numbers-with-same-consecutive-differences/
#Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
#Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.


class Solution(object):
    def numsSameConsecDiff(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        res = []
        if n == 1:
            res.append(0)
        for i in range(1, 10):
            self.dfs(n - 1, k, i, res)
        return res
        

    