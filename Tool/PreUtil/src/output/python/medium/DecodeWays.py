#https://leetcode.com/problems/decode-ways/
#A message containing letters from A-Z can be encoded into numbers using the following mapping:
#'A' -> "1"
#'B' -> "2"
#...
#'Z' -> "26"
#To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
#"AAJF" with the grouping (1 1 10 6)
#"KJF" with the grouping (11 10 6)
#Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
#Given a string s containing only digits, return the number of ways to decode it.
#The test cases are generated so that the answer fits in a 32-bit integer.


class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s or s[0] == '0':
            return 0
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, len(s) + 1):
            if s[i - 1] != '0':
                dp[i] += dp[i - 1]
            if s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] < '7'):
                dp[i] += dp[i - 2]
        return dp[-1]
        

    