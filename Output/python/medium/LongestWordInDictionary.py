#https://leetcode.com/problems/longest-word-in-dictionary/
#Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
#If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
#Note that the word should be built from left to right with each additional character being added to the end of a previous word. 


class Solution(object):
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        res = ""
        for word in words:
            if len(word) > len(res) or (len(word) == len(res) and word < res):
                if all(word[:k] in words for k in range(1, len(word))):
                    res = word
        return res
        

    