#https://leetcode.com/problems/shortest-common-supersequence/
#Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
#A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.


class Solution(object):
    def shortestCommonSupersequence(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """      
        def get_lcs(str1, str2):
            m = len(str1)
            n = len(str2)
            dp = [[0] * (n+1) for _ in range(m+1)]
            for i in range(m):
                for j in range(n):
                    if str1[i] == str2[j]:
                        dp[i+1][j+1] = dp[i][j] + 1
                    else:
                        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
            res = []
            i = m
            j = n
            while i > 0 and j > 0:
                if str1[i-1] == str2[j-1]:
                    res.append(str1[i-1])
                    i -= 1
                    j -= 1
                else:
                    if dp[i-1][j] > dp[i][j-1]:
                        i -= 1
                    else:
                        j -= 1
            return "".join(res[::-1])
        
        lcs = get_lcs(str1, str2)
        res = []
        i = j = k = 0
        while k < len(lcs):
            while i < len(str1) and str1[i] != lcs[k]:
                res.append(str1[i])
                i += 1
            while j < len(str2) and str2[j] != lcs[k]:
                res.append(str2[j])
                j += 1
            res.append(lcs[k])
            i += 1
            j += 1
            k += 1
        return "".join(res) + str1[i:] + str2[j:]

        
        
    