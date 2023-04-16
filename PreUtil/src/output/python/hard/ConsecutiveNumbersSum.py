#https://leetcode.com/problems/consecutive-numbers-sum/
#Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.


class Solution(object):
    def consecutiveNumbersSum(self, n):
        """
        :type n: int
        :rtype: int
        """      
        if n==1:
            return 1
        result=0
        for i in range(1,n):
            if (n-i*(i+1)/2)%i==0:
                result+=1
        return result
        
        
        
    