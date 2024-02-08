#https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
#Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
#Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
# 
#Example 1:
#Input: s = "abciiidef", k = 3
#Output: 3
#Explanation: The substring "iii" contains 3 vowel letters.
#Example 2:
#Input: s = "aeiou", k = 2
#Output: 2
#Explanation: Any substring of length 2 contains 2 vowels.
#Example 3:
#Input: s = "leetcode", k = 3
#Output: 2
#Explanation: "lee", "eet" and "ode" contain 2 vowels.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of lowercase English letters.
#	1 <= k <= s.length
class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        vowels = set(['a', 'e', 'i', 'o', 'u'])
        max_vowels = 0
        for i in range(len(s) - k + 1):
            max_vowels = max(max_vowels, len([x for x in s[i:i+k] if x in vowels]))
        return max_vowels