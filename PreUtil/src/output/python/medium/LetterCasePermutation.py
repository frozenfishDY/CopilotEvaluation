#https://leetcode.com/problems/letter-case-permutation/
#Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
#Return a list of all possible strings we could create. Return the output in any order.


class Solution(object):
    def letterCasePermutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = [s]
        for i in range(len(s)):
            if s[i].isalpha():
                res += [s[:i] + s[i].swapcase() + s[i+1:] for s in res]
        return res
        

    