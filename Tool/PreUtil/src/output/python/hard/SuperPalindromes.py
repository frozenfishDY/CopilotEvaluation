#https://leetcode.com/problems/super-palindromes/
#Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
#Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].


class Solution(object):
    def superpalindromesInRange(self, left, right):
        """
        :type left: str
        :type right: str
        :rtype: int
        """     
        if not left or not right:
            return 0
        if left==right:
            return 0
        if len(left)!=len(right):
            return 0
        if len(left)==1:
            return 0
        if len(left)==2:
            if left==right:
                return 0
            else:
                return 1
        # find the first different character
        for i in range(len(left)):
            if left[i]!=right[i]:
                break
        # swap the first different character
        left=left[:i]+right[i]+left[i+1:]
        return 1+self.superpalindromesInRange(left,right)
        
        
    