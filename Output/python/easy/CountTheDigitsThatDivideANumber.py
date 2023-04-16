#https://leetcode.com/problems/count-the-digits-that-divide-a-number/
#Given an integer num, return the number of digits in num that divide num.
#An integer val divides nums if nums % val == 0.


class Solution(object):
    def countDigits(self, num):
        """
        :type num: int
        :rtype: int
        """       
        count=0
        for i in str(num):
            if int(i)!=0 and num%int(i)==0:
                count+=1
        return count

        

    