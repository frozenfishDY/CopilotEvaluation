#https://leetcode.com/problems/subsequence-with-the-minimum-score/
#You are given two strings s and t.
#You are allowed to remove any number of characters from the string t.
#The score of the string is 0 if no characters are removed from the string t, otherwise:
#Let left be the minimum index among all removed characters.
#Let right be the maximum index among all removed characters.
#Then the score of the string is right - left + 1.
#Return the minimum possible score to make t a subsequence of s.
#A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).


class Solution(object):
    def minimumScore(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """       
        if not s or not t:
            return 0
        s = s[::-1]
        t = t[::-1]
        dp = [[0 for _ in range(len(t)+1)] for _ in range(len(s)+1)]
        for i in range(1,len(s)+1):
            for j in range(1,len(t)+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        return len(t) - dp[-1][-1]

        
        
    