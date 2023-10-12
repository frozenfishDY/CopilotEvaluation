#https://leetcode.com/problems/longest-palindromic-subsequence/
#Given a string s, find the longest palindromic subsequence's length in s.
#A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
# 
#Example 1:
#Input: s = "bbbab"
#Output: 4
#Explanation: One possible longest palindromic subsequence is "bbbb".
#Example 2:
#Input: s = "cbbd"
#Output: 2
#Explanation: One possible longest palindromic subsequence is "bb".
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists only of lowercase English letters.
class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        #Solution
        #1. Initialize the result to 0
        #2. Iterate through every character in s
        #3. For each character, find the longest palindrome subsequence
        #4. Return the result
        #
        #Example:
        #s = "bbbab"
        #ret: 4
        #
        #Time complexity: O(n^2)
        #Space complexity: O(1)

        ret = 0
        for i in range(len(s)):
            maxCount = 0
            for j in range(i, len(s)):
                if s[j] == s[i]:
                    maxCount += 1
                else:
                    break

            ret = max(ret, maxCount)

        return ret