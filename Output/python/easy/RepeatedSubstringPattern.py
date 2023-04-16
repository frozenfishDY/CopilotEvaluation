#https://leetcode.com/problems/repeated-substring-pattern/
#Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.


class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """ 
        if len(s)==0:
            return False
        if len(s)==1:
            return False
        for i in range(1,len(s)):
            if len(s)%i==0:
                res=""
                for j in range(0,len(s)/i):
                    res=res+s[0:i]
                if res==s:
                    return True
        return False

    