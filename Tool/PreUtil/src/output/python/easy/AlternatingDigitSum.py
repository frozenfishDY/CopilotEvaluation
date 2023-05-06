#https://leetcode.com/problems/alternating-digit-sum/
#You are given a positive integer n. Each digit of n has a sign according to the following rules:
#The most significant digit is assigned a positive sign.
#Each other digit has an opposite sign to its adjacent digits.
#Return the sum of all digits with their corresponding sign.


class Solution(object):
    def alternateDigitSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        res=0
        for i in range(len(str(n))):
            if i%2==0:
                res+=int(str(n)[i])
            else:
                res-=int(str(n)[i])
        return res

    