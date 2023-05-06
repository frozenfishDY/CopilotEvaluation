#https://leetcode.com/problems/hamming-distance/
#The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
#Given two integers x and y, return the Hamming distance between them.


class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """ 
        return bin(x^y).count('1')
        

    