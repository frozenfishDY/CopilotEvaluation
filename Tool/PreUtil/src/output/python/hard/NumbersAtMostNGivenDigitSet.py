#https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
#Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
#Return the number of positive integers that can be generated that are less than or equal to a given integer n.


class Solution(object):
    def atMostNGivenDigitSet(self, digits, n):
        """
        :type digits: List[str]
        :type n: int
        :rtype: int
        """
        if not digits:
            return 0
        if not n:
            return 0
        if len(digits)==1:
            return 1
        if len(digits)==n:
            return 1
        result = []
        for i in range(len(digits)-n+1):
            result.append(len(digits[i:i+n]))
        return min(result)
        
        
    