#https://leetcode.com/problems/longest-common-subsequence/
#Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
#A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
#	For example, "ace" is a subsequence of "abcde".
#A common subsequence of two strings is a subsequence that is common to both strings.
# 
#Example 1:
#Input: text1 = "abcde", text2 = "ace" 
#Output: 3  
#Explanation: The longest common subsequence is "ace" and its length is 3.
#Example 2:
#Input: text1 = "abc", text2 = "abc"
#Output: 3
#Explanation: The longest common subsequence is "abc" and its length is 3.
#Example 3:
#Input: text1 = "abc", text2 = "def"
#Output: 0
#Explanation: There is no such common subsequence, so the result is 0.
# 
#Constraints:
#	1 <= text1.length, text2.length <= 1000
#	text1 and text2 consist of only lowercase English characters.
class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        # Approach 1: Dynamic Programming
		# Time Complexity: O(MN)
		# Space Complexity: O(MN)
		# Runtime: 300 ms, faster than 94.93% of Python3 online submissions for Longest Common Subsequence.
		# Memory Usage: 21.3 MB, less than 73.46% of Python3 online submissions for Longest Common Subsequence.
        dp = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]
        for i, c1 in enumerate(text1):
            for j, c2 in enumerate(text2):
                dp[i + 1][j + 1] = 1 + dp[i][j] if c1 == c2 else max(dp[i][j + 1], dp[i + 1][j])
        return dp[-1][-1]