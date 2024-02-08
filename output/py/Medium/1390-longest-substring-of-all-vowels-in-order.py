#https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
#A string is considered beautiful if it satisfies the following conditions:
#	Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
#	The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
#For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
#Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
#A substring is a contiguous sequence of characters in a string.
# 
#Example 1:
#Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
#Output: 13
#Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
#Example 2:
#Input: word = "aeeeiiiioooauuuaeiou"
#Output: 5
#Explanation: The longest beautiful substring in word is "aeiou" of length 5.
#Example 3:
#Input: word = "a"
#Output: 0
#Explanation: There is no beautiful substring, so return 0.
# 
#Constraints:
#	1 <= word.length <= 5 * 105
#	word consists of characters 'a', 'e', 'i', 'o', and 'u'.
class Solution(object):
    def longestBeautifulSubstring(self, word):
        """
        :type word: str
        :rtype: int
        """
        res = 0
        for i in range(len(word)):
            if word[i] == 'a':
                j = i
                seen = set()
                while j < len(word) and word[j] >= word[j-1]:
                    seen.add(word[j])
                    j += 1
                if len(seen) == 5:
                    res = max(res, j - i)
        return res