#https://leetcode.com/problems/add-strings/
#Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
#You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.


class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """ 
        if len(num1)==0:
            return num2
        if len(num2)==0:
            return num1
        if len(num1)==1:
            return str(int(num1)+int(num2))
        if len(num2)==1:
            return str(int(num1)+int(num2))
        if len(num1)>len(num2):
            num2="0"*(len(num1)-len(num2))+num2
        else:
            num1="0"*(len(num2)-len(num1))+num1
        res=""
        carry=0
        for i in range(len(num1)-1,-1,-1):
            temp=int(num1[i])+int(num2[i])+carry
            res=str(temp%10)+res
            carry=temp/10
        if carry==1:
            res="1"+res
        return res

    