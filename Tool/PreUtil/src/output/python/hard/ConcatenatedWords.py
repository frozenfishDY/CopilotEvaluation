#https://leetcode.com/problems/concatenated-words/
#Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
#A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necesssarily distinct) in the given array.


class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """      
        if not words:
            return []
        result=[]
        for word in words:
            if self.isConcatenated(word,words):
                result.append(word)
        return result
        
        
    