#https://leetcode.com/problems/base-7/
#Given an integer num, return a string of its base 7 representation.


class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """       
        if num==0:
            return "0"
        res=""
        if num<0:
            res="-"
            num=-num
        while num>0:
            res=res+str(num%7)
            num=num//7
        return res[::-1]

    