#https://leetcode.com/problems/longest-palindromic-substring/
#Given a string s, return the longest palindromic substring in s.


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """ 
        res = ""
        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                if len(set(s[i:j])) == j-i:
                    res = max(res,s[i:j],key=len)
        return res
        

    