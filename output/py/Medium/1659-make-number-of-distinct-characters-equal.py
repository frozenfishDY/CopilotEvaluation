#https://leetcode.com/problems/make-number-of-distinct-characters-equal/
#You are given two 0-indexed strings word1 and word2.
#A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
#Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.


class Solution(object):
    def isItPossible(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: bool
        """
        if len(word1) > len(word2):
            word1, word2 = word2, word1
        if len(word2) - len(word1) > 1:
            return False
        if len(word2) == len(word1):
            return len(set(word1 + word2)) == 1
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                return word1[i + 1:] == word2[i + 1:]
        return True
        

    