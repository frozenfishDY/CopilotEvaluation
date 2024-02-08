#https://leetcode.com/problems/maximum-length-of-repeated-subarray/
#Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.


class Solution(object):
    def findLength(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        res = 0
        dp = [[0]*(len(nums2)+1) for _ in range(len(nums1)+1)]
        for i in range(1,len(nums1)+1):
            for j in range(1,len(nums2)+1):
                if nums1[i-1] == nums2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                    res = max(res,dp[i][j])
        return res
        

    