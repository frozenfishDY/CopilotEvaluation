#https://leetcode.com/problems/custom-sort-string/
#You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
#Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
#Return any permutation of s that satisfies this property.


class Solution(object):
    def customSortString(self, order, s):
        """
        :type order: str
        :type s: str
        :rtype: str
        """       
        res = ""
        for i in range(len(order)):
            for j in range(len(s)):
                if order[i] == s[j]:
                    res += order[i]
        for i in range(len(s)):
            if s[i] not in res:
                res += s[i]
        return res

        

    