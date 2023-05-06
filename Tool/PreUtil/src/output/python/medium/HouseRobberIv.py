#https://leetcode.com/problems/house-robber-iv/
#There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
#The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
#You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.
#You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.
#Return the minimum capability of the robber out of all the possible ways to steal at least k houses.


class Solution(object):
    def minCapability(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """ 
        n = len(nums)
        dp = [0] * (n+1)
        for i in range(n-1, -1, -1):
            dp[i] = max(dp[i+1], nums[i] + dp[i+2])
        return dp[0]
        
        

    