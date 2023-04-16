#https://leetcode.com/problems/valid-palindrome-ii/
#Given a string s, return true if the s can be palindrome after deleting at most one character from it.


class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """       
        if s==s[::-1]:
            return True
        else:
            for i in range(len(s)):
                if s[i]!=s[len(s)-1-i]:
                    return s[i:len(s)-1-i]==s[i:len(s)-1-i][::-1] or s[i+1:len(s)-i]==s[i+1:len(s)-i][::-1]
        return False
        

    