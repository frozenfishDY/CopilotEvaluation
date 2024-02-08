#https://leetcode.com/problems/sum-of-number-and-its-reverse/
#Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.


class Solution(object):
    def sumOfNumberAndReverse(self, num):
        """
        :type num: int
        :rtype: bool
        """ 
        # 1. find the reverse of the number
        # 2. find the sum of the number and its reverse
        # 3. return true if the sum is equal to the number
        # 4. return false otherwise
        # 1. find the reverse of the number
        reverse=self.reverse(num)
        # 2. find the sum of the number and its reverse
        sum=num+reverse
        # 3. return true if the sum is equal to the number
        # 4. return false otherwise
        return sum==num

        
    