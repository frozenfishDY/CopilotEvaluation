#https://leetcode.com/problems/maximum-sum-circular-subarray/
#Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
#A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
#A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.


class Solution(object):
    def maxSubarraySumCircular(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """                                                                                 
        max_sum = nums[0]
        min_sum = nums[0]
        total_sum = nums[0]
        max_res = nums[0]
        min_res = nums[0]
        for i in range(1,len(nums)):
            max_sum = max(max_sum+nums[i],nums[i])
            min_sum = min(min_sum+nums[i],nums[i])
            total_sum += nums[i]
            max_res = max(max_res,max_sum)
            min_res = min(min_res,min_sum)
        if max_res > 0:
            return max(max_res,total_sum-min_res)
        else:
            return max_res

        

    