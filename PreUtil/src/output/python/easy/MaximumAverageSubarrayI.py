#https://leetcode.com/problems/maximum-average-subarray-i/
#You are given an integer array nums consisting of n elements, and an integer k.
#Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.


class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """     
        max_sum=0
        for i in range(k):
            max_sum+=nums[i]
        sum=max_sum
        for i in range(k,len(nums)):
            sum=sum-nums[i-k]+nums[i]
            max_sum=max(max_sum,sum)
        return max_sum/k
        

    