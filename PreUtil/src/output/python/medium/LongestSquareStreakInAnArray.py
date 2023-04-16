#https://leetcode.com/problems/longest-square-streak-in-an-array/
#You are given an integer array nums. A subsequence of nums is called a square streak if:
#The length of the subsequence is at least 2, and
#after sorting the subsequence, each element (except the first element) is the square of the previous number.
#Return the length of the longest square streak in nums, or return -1 if there is no square streak.
#A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


class Solution(object):
    def longestSquareStreak(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """       
        res = 0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[j] == nums[i]*nums[i]:
                    res = max(res,j-i+1)
                elif nums[j] > nums[i]*nums[i]:
                    break
        return res if res > 1 else -1

        

    