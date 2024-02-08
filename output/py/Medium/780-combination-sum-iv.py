#https://leetcode.com/problems/combination-sum-iv/
#Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
#The test cases are generated so that the answer can fit in a 32-bit integer.


class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = [0]*(target+1)
        dp[0] = 1
        for i in range(1,target+1):
            for j in range(len(nums)):
                if i >= nums[j]:
                    dp[i] += dp[i-nums[j]]
        return dp[target]
        

    