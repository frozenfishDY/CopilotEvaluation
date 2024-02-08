#https://leetcode.com/problems/jump-game/
#You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
#Return true if you can reach the last index, or false otherwise.


class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """ 
        n = len(nums)
        if n == 1:
            return True
        if nums[0] >= n-1:
            return True
        dp = [0] * n
        for i in range(n):
            for j in range(1, nums[i]+1):
                if i+j >= n-1:
                    return True
                if dp[i+j] == 0:
                    dp[i+j] = dp[i]+1
        return False
        

    