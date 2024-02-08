#https://leetcode.com/problems/palindromic-substrings/
#Given a string s, return the number of palindromic substrings in it.
#A string is a palindrome when it reads the same backward as forward.
#A substring is a contiguous sequence of characters within the string.
# 
#Example 1:
#Input: s = "abc"
#Output: 3
#Explanation: Three palindromic strings: "a", "b", "c".
#Example 2:
#Input: s = "aaa"
#Output: 6
#Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists of lowercase English letters.
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """    
        #Solution
        #1. Iterate through every character in s
        #2. For each character, find the number of palindromic substrings with it as the center
        #3. Return the result
        #
        #Example:
        #s = "abc"
        #ret: 3
        #
        #Time complexity: O(n^2)
        #Space complexity: O(1)
        
        ret = 0
        for i in range(len(s)):
            ret += self.countPalindromicSubstrings(s, i, i)
            ret += self.countPalindromicSubstrings(s, i, i + 1)
        return ret
    