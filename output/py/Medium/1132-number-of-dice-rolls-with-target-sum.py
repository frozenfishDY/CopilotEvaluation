#https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#You have n dice, and each die has k faces numbered from 1 to k.
#Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
# 
#Example 1:
#Input: n = 1, k = 6, target = 3
#Output: 1
#Explanation: You throw one die with 6 faces.
#There is only one way to get a sum of 3.
#Example 2:
#Input: n = 2, k = 6, target = 7
#Output: 6
#Explanation: You throw two dice, each with 6 faces.
#There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
#Example 3:
#Input: n = 30, k = 30, target = 500
#Output: 222616187
#Explanation: The answer must be returned modulo 109 + 7.
# 
#Constraints:
#	1 <= n, k <= 30
#	1 <= target <= 1000
class Solution(object):
    def numRollsToTarget(self, n, k, target):
        """
        :type n: int
        :type k: int
        :type target: int
        :rtype: int
        """
        # Approach 1: Dynamic Programming
		# Runtime: 4028 ms, faster than 5.03% of Python online submissions for Number of Dice Rolls With Target Sum.
		# Memory Usage: 14.9 MB, less than 100.00% of Python online submissions for Number of Dice Rolls With Target Sum.
        dp = [[0] * (target + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            for j in range(i, target + 1):
                for l in range(1, k + 1):
                    if j - l < 0:
                        break
                    dp[i][j] += dp[i - 1][j - l]
        return dp[n][target] % (10 ** 9 + 7)