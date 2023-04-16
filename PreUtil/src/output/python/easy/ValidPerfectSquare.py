#https://leetcode.com/problems/valid-perfect-square/
#Given a positive integer num, return true if num is a perfect square or false otherwise.
#A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
#You must not use any built-in library function, such as sqrt.


class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """ 
        if num==1:
            return True
        if num==0:
            return False
        for i in range(1,num/2+1):
            if i*i==num:
                return True
        return False

    