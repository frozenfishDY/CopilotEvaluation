#https://leetcode.com/problems/jump-game-ii/
#You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
#Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
#0 <= j <= nums[i] and
#i + j < n
#Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].


class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 1:
            return 0
        if nums[0] >= n-1:
            return 1
        dp = [0] * n
        for i in range(n):
            for j in range(1, nums[i]+1):
                if i+j >= n-1:
                    return dp[i]+1
                if dp[i+j] == 0:
                    dp[i+j] = dp[i]+1
        return dp[n-1]
        

    