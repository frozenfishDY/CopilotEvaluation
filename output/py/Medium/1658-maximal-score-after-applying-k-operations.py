#https://leetcode.com/problems/maximal-score-after-applying-k-operations/
#You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
#In one operation:
#choose an index i such that 0 <= i < nums.length,
#increase your score by nums[i], and
#replace nums[i] with ceil(nums[i] / 3).
#Return the maximum possible score you can attain after applying exactly k operations.
#The ceiling function ceil(val) is the least integer greater than or equal to val.


class Solution(object):
    def maxKelements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res = 0
        for i in range(k+1):
            if i <= len(nums) and k-i <= len(nums):
                res = max(res,sum(sorted(nums)[-i:])*min(sorted(nums)[:k-i]))
        return res
        

    