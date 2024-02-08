#https://leetcode.com/problems/to-lower-case/
#Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.


class Solution(object):
    def toLowerCase(self, s):
        """
        :type s: str
        :rtype: str
        """      
        res=""
        for i in range(len(s)):
            if ord(s[i])>=65 and ord(s[i])<=90:
                res+=chr(ord(s[i])+32)
            else:
                res+=s[i]
        return res
        

    