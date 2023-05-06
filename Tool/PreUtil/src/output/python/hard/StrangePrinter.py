#https://leetcode.com/problems/strange-printer/
#There is a strange printer with the following two special properties:
#The printer can only print a sequence of the same character each time.
#At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
#Given a string s, return the minimum number of turns the printer needed to print it.


class Solution(object):
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """       
        if not s:
            return 0
        dp = [[0 for _ in range(len(s))] for _ in range(len(s))]
        for i in range(len(s)-1,-1,-1):
            dp[i][i] = 1
            for j in range(i+1,len(s)):
                if s[i] == s[j]:
                    dp[i][j] = dp[i][j-1]
                else:
                    dp[i][j] = min(dp[i][k]+dp[k+1][j] for k in range(i,j))
        return dp[0][-1]

        
        
    