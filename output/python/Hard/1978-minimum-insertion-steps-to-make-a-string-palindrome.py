#https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
#Given a string s. In one step you can insert any character at any index of the string.
#Return the minimum number of steps to make s palindrome.
#A Palindrome String is one that reads the same backward as well as forward.
# 
#Example 1:
#Input: s = "zzazz"
#Output: 0
#Explanation: The string "zzazz" is already palindrome we do not need any insertions.
#Example 2:
#Input: s = "mbadm"
#Output: 2
#Explanation: String can be "mbdadbm" or "mdbabdm".
#Example 3:
#Input: s = "leetcode"
#Output: 5
#Explanation: Inserting 5 characters the string becomes "leetcodocteel".
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of lowercase English letters.
class Solution(object):
    def minInsertions(self, s):
        """
        :type s: str
        :rtype: int
        """
        #DP
        #Time:  O(n^2)
        #Space: O(n)
        dp = [0] * len(s)
        for i in reversed(range(len(s) - 1)):
            pre = 0
            for j in range(i + 1, len(s)):
                tmp = dp[j]
                dp[j] = pre if s[i] == s[j] else 1 + min(dp[j], dp[j - 1])
                pre = tmp
        return dp[-1]