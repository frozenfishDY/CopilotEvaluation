#https://leetcode.com/problems/partition-array-into-disjoint-intervals/
#Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:
#Every element in left is less than or equal to every element in right.
#left and right are non-empty.
#left has the smallest possible size.
#Return the length of left after such a partitioning.
#Test cases are generated such that partitioning exists.


class Solution(object):
    def partitionDisjoint(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_left = nums[0]
        max_all = nums[0]
        res = 1
        for i in range(1,len(nums)):
            if nums[i] < max_left:
                max_left = max_all
                res = i + 1
            else:
                max_all = max(max_all,nums[i])
        return res
        

    