#https://leetcode.com/problems/nth-magical-number/
#A positive integer is magical if it is divisible by either a or b.
#Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 10^9 + 7.


class Solution(object):
    def nthMagicalNumber(self, n, a, b):
        """
        :type n: int
        :type a: int
        :type b: int
        :rtype: int
        """      
        if n==1:
            return min(a,b)
        if a==b:
            return a*n
        if a>b:
            a,b=b,a
        result=0
        for i in range(n):
            if i%2==0:
                result+=a
            else:
                result+=b
        return result
        
        
    