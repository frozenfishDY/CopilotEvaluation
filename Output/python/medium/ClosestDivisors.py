#https://leetcode.com/problems/closest-divisors/
#Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
#Return the two integers in any order.


class Solution(object):
    def closestDivisors(self, num):
        """
        :type num: int
        :rtype: List[int]
        """ 
        def getDivisors(n):
            for i in range(int(math.sqrt(n)), 0, -1):
                if n % i == 0:
                    return [i, n / i]
        a, b = getDivisors(num + 1)
        c, d = getDivisors(num + 2)
        return [a, b] if b - a < d - c else [c, d]
            
           

    