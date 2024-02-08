#https://leetcode.com/problems/longest-palindrome/
#Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
#Letters are case sensitive, for example, "Aa" is not considered a palindrome here.


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """ 
        if len(s)==0:
            return 0
        if len(s)==1:
            return 1
        res=0
        for i in range(0,len(s)):
            if s.count(s[i])%2==0:
                res=res+s.count(s[i])
            else:
                res=res+s.count(s[i])-1
        if res<len(s):
            res=res+1
        return res

    