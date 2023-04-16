#https://leetcode.com/problems/distinct-subsequences-ii/
#Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
#A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.


class Solution(object):
    def distinctSubseqII(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        if len(s)==1:
            return 1
        if len(s)==2:
            return 2
        result = 0
        for i in range(len(s)):
            result+=self.distinctSubseqII(s[:i]+s[i+1:])
        return result%(10**9+7)
        
        
    