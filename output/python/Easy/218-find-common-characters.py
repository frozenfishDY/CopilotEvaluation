#https://leetcode.com/problems/find-common-characters/
#Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
# 
#Example 1:
#Input: words = ["bella","label","roller"]
#Output: ["e","l","l"]
#Example 2:
#Input: words = ["cool","lock","cook"]
#Output: ["c","o"]
# 
#Constraints:
#	1 <= words.length <= 100
#	1 <= words[i].length <= 100
#	words[i] consists of lowercase English letters.
class Solution(object):
    def commonChars(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result = []
        for c in set(words[0]):
            count = min([w.count(c) for w in words])
            result += [c]*count
        return result