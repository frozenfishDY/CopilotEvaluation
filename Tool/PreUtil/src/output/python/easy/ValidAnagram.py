#https://leetcode.com/problems/valid-anagram/
#Given two strings s and t, return true if t is an anagram of s, and false otherwise.
#An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """ 
        if len(s)!=len(t):
            return False
        dict={}
        for i in range(0,len(s)):
            if s[i] in dict:
                dict[s[i]]+=1
            else:
                dict[s[i]]=1
        for i in range(0,len(t)):
            if t[i] in dict:
                dict[t[i]]-=1
            else:
                return False
        for key in dict:
            if dict[key]!=0:
                return False
        return True

    