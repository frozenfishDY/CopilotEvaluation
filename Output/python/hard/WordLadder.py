#https://leetcode.com/problems/word-ladder/
#A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
#Every adjacent pair of words differs by a single letter.
#Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
#sk == endWord
#Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.


class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """      
        if endWord not in wordList:
            return 0
        wordList = set(wordList)
        wordList.discard(beginWord)
        wordList.discard(endWord)
        begin_set = {beginWord}
        end_set = {endWord}
        visited = set()
        res = []
        self.dfs(begin_set, end_set, wordList, visited, res, [beginWord])
        return res

        
        
    