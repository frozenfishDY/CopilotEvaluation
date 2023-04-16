#https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
#You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
#The chosen integers have to be in the range [1, n].
#Each integer can be chosen at most once.
#The chosen integers should not be in the array banned.
#The sum of the chosen integers should not exceed maxSum.
#Return the maximum number of integers you can choose following the mentioned rules.


class Solution(object):
    def maxCount(self, banned, n, maxSum):
        """
        :type banned: List[int]
        :type n: int
        :type maxSum: int
        :rtype: int
        """      
        banned.sort()
        res = 0
        for i in range(n):
            if i+1 not in banned:
                if maxSum >= i+1:
                    res += 1
                    maxSum -= i+1
                else:
                    break
        return res
        

    