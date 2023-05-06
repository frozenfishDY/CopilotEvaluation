#https://leetcode.com/problems/binary-subarrays-with-sum/
#Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
#A subarray is a contiguous part of the array.


class Solution(object):
    def numSubarraysWithSum(self, nums, goal):
        """
        :type nums: List[int]
        :type goal: int
        :rtype: int
        """
        res = 0
        sum = 0
        count = {}
        for i in range(len(nums)):
            sum += nums[i]
            if sum == goal:
                res += 1
            if sum-goal in count:
                res += count[sum-goal]
            if sum in count:
                count[sum] += 1
            else:
                count[sum] = 1
        return res
        

    