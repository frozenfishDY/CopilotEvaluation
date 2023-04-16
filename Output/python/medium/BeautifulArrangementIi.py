#https://leetcode.com/problems/beautiful-arrangement-ii/
#Given two integers n and k, construct a list answer that contains n different positive integers ranging from 1 to n and obeys the following requirement:
#Suppose this list is answer = [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
#Return the list answer. If there multiple valid answers, return any of them.


class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        res = 0
        for i in range(1,n+1):
            for j in range(i+1,n+1):
                if abs(i-j) > res:
                    res = abs(i-j)
        return res
        

    