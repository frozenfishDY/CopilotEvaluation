#https://leetcode.com/problems/number-of-matching-subsequences/
#Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
#A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
#For example, "ace" is a subsequence of "abcde".


class Solution(object):
    def numMatchingSubseq(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: int
        """                       
        res = 0
        for word in words:
            i = 0
            for c in s:
                if i < len(word) and c == word[i]:
                    i += 1
            if i == len(word):
                res += 1
        return res

        

    