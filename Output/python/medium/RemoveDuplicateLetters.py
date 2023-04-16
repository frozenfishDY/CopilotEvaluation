#https://leetcode.com/problems/remove-duplicate-letters/
#Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.


class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = []
        for i, c in enumerate(s):
            if c not in res:
                while res and c < res[-1] and s.find(res[-1], i) != -1:
                    res.pop()
                res.append(c)
        return "".join(res)
        

    