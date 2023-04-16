#https://leetcode.com/problems/longest-arithmetic-subsequence/
#Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
#Note that:
#A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
#A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).


class Solution(object):
    def longestArithSeqLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """       
        dp = [collections.defaultdict(int) for _ in range(len(nums))]
        res = 0
        for i in range(1,len(nums)):
            for j in range(i):
                diff = nums[i]-nums[j]
                dp[i][diff] = dp[j][diff]+1
                res = max(res,dp[i][diff])
        return res+1

        

    