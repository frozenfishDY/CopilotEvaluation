#https://leetcode.com/problems/find-the-shortest-superstring/
#Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
#You may assume that no string in words is a substring of another string in words.


class Solution(object):
    def shortestSuperstring(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        if not words:
            return ""
        if len(words)==1:
            return words[0]
        if len(words)==2:
            return self.merge(words[0],words[1])
        result = ""
        for i in range(len(words)):
            result = self.merge(result,self.shortestSuperstring(words[:i]+words[i+1:]))
        return result
        
        
    