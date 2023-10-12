#https://leetcode.com/problems/stone-game-ii/
#Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 
#Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
#On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
#The game continues until all the stones have been taken.
#Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
# 
#Example 1:
#Input: piles = [2,7,9,4,4]
#Output: 10
#Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
#Example 2:
#Input: piles = [1,2,3,4,5,100]
#Output: 104
# 
#Constraints:
#	1 <= piles.length <= 100
#	1 <= piles[i] <= 104
class Solution(object):
    def stoneGameII(self, piles):
        """
        :type piles: List[int]
        :rtype: int
        """
        # Approach 1: Recursion with Memoization
        # Time Complexity: O(N^3)
        # Space Complexity: O(N^2)
        # Runtime: 28 ms, faster than 74.07% of Python online submissions for Stone Game II.
        # Memory Usage: 14.4 MB, less than 100.00% of Python online submissions for Stone Game II.
        # memo = {}
        # def dfs(piles, M, i):
        #     if i >= len(piles):
        #         return 0
        #     if (i, M) in memo:
        #         return memo[(i, M)]
        #     ans, take, stones = float('-inf'), 0, 0
        #     for j in range(i, min(i + 2 * M, len(piles))):
        #         stones += piles[j]
        #         take = stones + dfs(piles, max(M, j - i + 1), j + 1)
        #         ans = max(ans, take)
        #     memo[(i, M)] = ans
        #     return ans
        # return dfs(piles, 1, 0)
        
        # Approach 2: Dynamic Programming
        # Time Complexity: O(N^2)
        # Space Complexity: O(N^2)
        # Runtime: 28 ms, faster than 74.07% of Python online submissions for Stone Game II.
        # Memory Usage: 13.9 MB, less than 100.00% of Python online submissions for Stone Game II.
        N = len(piles)
        dp = [[0] * (N + 1) for _ in range(N + 1)]
        for i in range(N - 1, -1, -1):
            for M in range(N + 1):
                stones = 0
                for j in range(i, min(i + 2 * M, N)):
                    stones += piles[j]
                    dp[i][M] = max(dp[i][M], stones - dp[j + 1][max(M, j - i + 1)])
        return dp[0][1]