#https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
#Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
# 
#Example 1:
#Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
#Output: "apple"
#Example 2:
#Input: s = "abpcplea", dictionary = ["a","b","c"]
#Output: "a"
# 
#Constraints:
#	1 <= s.length <= 1000
#	1 <= dictionary.length <= 1000
#	1 <= dictionary[i].length <= 1000
#	s and dictionary[i] consist of lowercase English letters.
class Solution(object):
    def findLongestWord(self, s, dictionary):
        """
        :type s: str
        :type dictionary: List[str]
        :rtype: str
        """
        #Solution
        #1. For each word in dictionary, check if it is a subsequence of s
        #2. If it is, return the word
        #3. Return empty string
        #
        #Example:
        #s: "abpcplea", dictionary: ["ale","apple","monkey","plea"]
        #ret: "apple"
        #
        #Time complexity: O(n^2)
        #Space complexity: O(1)

        dictionary.sort(key=lambda x: (-len(x), x))
        for word in dictionary:
            i = 0
            for c in s:
                if i < len(word) and word[i] == c:
                    i += 1
            if i == len(word):
                return word

        return ""