#https://leetcode.com/problems/integer-break/
#Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
#Return the maximum product you can get.
# 
#Example 1:
#Input: n = 2
#Output: 1
#Explanation: 2 = 1 + 1, 1 × 1 = 1.
#Example 2:
#Input: n = 10
#Output: 36
#Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
# 
#Constraints:
#	2 <= n <= 58
class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [i - 1 for i in range(n + 1)]
        for i in range(2, n + 1):
            for j in range(1, i // 2 + 1):
                dp[i] = max(dp[i], dp[j] * dp[i - j])
        return dp[n]