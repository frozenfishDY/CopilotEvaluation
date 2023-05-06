#https://leetcode.com/problems/partition-array-for-maximum-sum/
#Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
#Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.


class Solution(object):
    def maxSumAfterPartitioning(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """       
        dp = [0]*(len(arr)+1)
        for i in range(1,len(arr)+1):
            max_num = 0
            for j in range(1,k+1):
                if i-j>=0:
                    max_num = max(max_num,arr[i-j])
                    dp[i] = max(dp[i],dp[i-j]+max_num*j)
        return dp[len(arr)]

        

    