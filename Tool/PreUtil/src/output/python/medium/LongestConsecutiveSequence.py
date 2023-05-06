#https://leetcode.com/problems/longest-consecutive-sequence/
#Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
#You must write an algorithm that runs in O(n) time.


class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """       
        res = 0
        nums = set(nums)
        for i in nums:
            if i-1 not in nums:
                j = i+1
                while j in nums:
                    j+=1
                res = max(res,j-i)
        return res

        

    