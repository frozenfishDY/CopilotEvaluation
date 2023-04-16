#https://leetcode.com/problems/valid-permutations-for-di-sequence/
#You are given a string s of length n where s[i] is either:
#'D' means decreasing, or
#'I' means increasing.
#A permutation perm of n + 1 integers of all the integers in the range [0, n] is called a valid permutation if for all valid i:
#If s[i] == 'D', then perm[i] > perm[i + 1], and
#If s[i] == 'I', then perm[i] < perm[i + 1].
#Return the number of valid permutations perm. Since the answer may be large, return it modulo 109 + 7.


class Solution(object):
    def numPermsDISequence(self, s):
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
            if s[i]=='D':
                result+=self.numPermsDISequence(s[:i]+s[i+1:])
            else:
                result+=self.numPermsDISequence(s[:i]+s[i+1:])
        return result%(10**9+7)
        
        
    