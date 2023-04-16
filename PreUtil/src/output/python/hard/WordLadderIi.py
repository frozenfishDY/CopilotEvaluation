#https://leetcode.com/problems/word-ladder-ii/
#A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
#Every adjacent pair of words differs by a single letter.
#Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
#sk == endWord
#Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].


class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """      
        if endWord not in wordList:
            return []
        wordList = set(wordList)
        wordList.discard(beginWord)
        wordList.discard(endWord)
        begin_set = {beginWord}
        end_set = {endWord}
        visited = set()
        res = []
        self.dfs(begin_set, end_set, wordList, visited, res, [beginWord])
        return res

        
        
    