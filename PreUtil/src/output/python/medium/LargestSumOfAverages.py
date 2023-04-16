#https://leetcode.com/problems/largest-sum-of-averages/
#You are given an integer array nums and an integer k. You can partition the array into at most k non-empty adjacent subarrays. The score of a partition is the sum of the averages of each subarray.
#Note that the partition must use every integer in nums, and that the score is not necessarily an integer.
#Return the maximum score you can achieve of all the possible partitions. Answers within 10-6 of the actual answer will be accepted.


class Solution(object):
    def largestSumOfAverages(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        res = 0
        for i in range(len(nums)):
            for j in range(i,len(nums)):
                if max(nums[i:j+1]) >= left and max(nums[i:j+1]) <= right:
                    res += 1
        return res
        

    