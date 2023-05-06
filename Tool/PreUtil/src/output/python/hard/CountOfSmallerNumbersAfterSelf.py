#https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].


class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        res = [0] * len(nums)
        sorted_nums = []
        for i in range(len(nums)-1, -1, -1):
            index = self.bisect_left(sorted_nums, nums[i])
            res[i] = index
            sorted_nums.insert(index, nums[i])
        return res
        
        
    