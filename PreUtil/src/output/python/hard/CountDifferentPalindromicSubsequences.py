#https://leetcode.com/problems/count-different-palindromic-subsequences/
#Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.
#A subsequence of a string is obtained by deleting zero or more characters from the string.
#A sequence is palindromic if it is equal to the sequence reversed.
#Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.


class Solution(object):
    def countPalindromicSubsequences(self, s):
        """
        :type s: str
        :rtype: int
        """     
        if not s:
            return 0
        if len(s)==1:
            return 1
        if len(s)==2:
            return 2
        if len(s)==3:
            return 4
        dp=[[0 for i in range(len(s))] for j in range(len(s))]
        for i in range(len(s)):
            dp[i][i]=1
        for i in range(len(s)-1):
            dp[i][i+1]=2
        for i in range(len(s)-2):
            dp[i][i+2]=4
        for i in range(3,len(s)):
            for j in range(len(s)-i):
                if s[j]==s[j+i]:
                    dp[j][j+i]=dp[j+1][j+i-1]*2
                    left=j+1
                    right=j+i-1
                    while left<=right and s[left]!=s[j]:
                        left+=1
                    while left<=right and s[right]!=s[j]:
                        right-=1
                    if left>right:
                        dp[j][j+i]-=1
                    elif left==right:
                        dp[j][j+i]-=2
                    else:
                        dp[j][j+i]-=dp[left+1][right-1]*2
                else:
                    dp[j][j+i]=dp[j+1][j+i]+dp[j][j+i-1]-dp[j+1][j+i-1]
        return dp[0][len(s)-1]%1000000007
        
        
    