#https://leetcode.com/problems/powx-n/
#Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).


class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n==0:
            return 1
        if n<0:
            return 1/self.myPow(x,-n)
        if n%2==0:
            return self.myPow(x*x,n/2)
        else:
            return x*self.myPow(x*x,n/2)
        

    