#https://leetcode.com/problems/shortest-palindrome/
#You are given a string s. You can convert s to a palindrome by adding characters in front of it.
#Return the shortest palindrome you can find by performing this transformation.


class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return s
        rev_s = s[::-1]
        for i in range(len(s)):
            if s.startswith(rev_s[i:]):
                return rev_s[:i] + s
        
        
    