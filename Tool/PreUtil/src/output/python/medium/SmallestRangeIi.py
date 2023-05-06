#https://leetcode.com/problems/smallest-range-ii/
#You are given an integer array nums and an integer k.
#For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.
#The score of nums is the difference between the maximum and minimum elements in nums.
#Return the minimum score of nums after changing the values at each index.


class Solution(object):
    def smallestRangeII(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        res = nums[-1] - nums[0]
        for i in range(len(nums)-1):
            res = min(res,max(nums[-1]-k,nums[i]+k)-min(nums[0]+k,nums[i+1]-k))
        return res
        

    