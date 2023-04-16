#https://leetcode.com/problems/k-similar-strings/
#Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
#Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.


class Solution(object):
    def kSimilarity(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """     
        if not s1 or not s2:
            return 0
        if s1==s2:
            return 0
        if len(s1)!=len(s2):
            return 0
        if len(s1)==1:
            return 0
        if len(s1)==2:
            if s1==s2:
                return 0
            else:
                return 1
        # find the first different character
        for i in range(len(s1)):
            if s1[i]!=s2[i]:
                break
        # swap the first different character
        s1=s1[:i]+s2[i]+s1[i+1:]
        return 1+self.kSimilarity(s1,s2)

        
        
    