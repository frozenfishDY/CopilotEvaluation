#https://leetcode.com/problems/count-of-range-sum/
#Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.
#Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.


class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        if not nums:
            return 0
        res = 0
        sums = [0]
        for num in nums:
            sums.append(sums[-1] + num)
        self.merge_sort(sums, 0, len(sums), lower, upper)
        return res
        
        
    