#https://leetcode.com/problems/word-break-ii/
#Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.
#Note that the same word in the dictionary may be reused multiple times in the segmentation.


class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        wordDict = set(wordDict)
        memo = {}
        return self.dfs(s, wordDict, memo)
        
        
    