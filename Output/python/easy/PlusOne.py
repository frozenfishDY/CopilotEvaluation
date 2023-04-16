#https://leetcode.com/problems/plus-one/
#You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
#Increment the large integer by one and return the resulting array of digits.


class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """       
        res=[]
        carry=1
        for i in range(len(digits)-1,-1,-1):
            res.append((digits[i]+carry)%10)
            carry=(digits[i]+carry)/10
        if carry==1:
            res.append(1)
        res.reverse()
        return res


    