#https://leetcode.com/problems/integer-replacement/
#Given a positive integer n, you can apply one of the following operations:
#If n is even, replace n with n / 2.
#If n is odd, replace n with either n + 1 or n - 1.
#Return the minimum number of operations needed for n to become 1.


class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0
        while n != 1:
            if n % 2 == 0:
                n /= 2
            elif n == 3 or n % 4 == 1:
                n -= 1
            else:
                n += 1
            res += 1
        return res
        

    