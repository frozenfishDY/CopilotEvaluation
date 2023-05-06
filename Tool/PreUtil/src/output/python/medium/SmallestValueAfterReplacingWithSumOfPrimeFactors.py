#https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
#You are given a positive integer n.
#Continuously replace n with the sum of its prime factors.
#Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
#Return the smallest value n will take on.


class Solution(object):
    def smallestValue(self, n):
        """
        :type n: int
        :rtype: int
        """                                                                                        
        res = 0
        while n > 1:
            res += self.findSmallestPrimeFactor(n)
            n = n // self.findSmallestPrimeFactor(n)
        return res


        

    