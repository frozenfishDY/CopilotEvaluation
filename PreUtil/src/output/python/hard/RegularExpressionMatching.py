#https://leetcode.com/problems/regular-expression-matching/
#Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
#'.' Matches any single character
#'*' Matches zero or more of the preceding element.
#The matching should cover the entire input string (not partial).


class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """       
        if not p:
            return not s
        if len(p)==1 or p[1]!='*':
            if not s or (p[0]!='.' and p[0]!=s[0]):
                return False
            return self.isMatch(s[1:],p[1:])
        else:
            i=-1
            length=len(s)
            while i<length and (i<0 or p[0]=='.' or p[0]==s[i]):
                if self.isMatch(s[i+1:],p[2:]):
                    return True
                i+=1
            return False

        
    