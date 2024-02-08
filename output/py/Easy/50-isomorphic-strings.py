#https://leetcode.com/problems/isomorphic-strings/
#Given two strings s and t, determine if they are isomorphic.
#Two strings s and t are isomorphic if the characters in s can be replaced to get t.
#All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """ 
        if len(s)!=len(t):
            return False
        s2t={}
        t2s={}
        for i in range(len(s)):
            if s[i] in s2t:
                if s2t[s[i]]!=t[i]:
                    return False
            else:
                s2t[s[i]]=t[i]
            if t[i] in t2s:
                if t2s[t[i]]!=s[i]:
                    return False
            else:
                t2s[t[i]]=s[i]
        return True

    