#https://leetcode.com/problems/minimum-absolute-sum-difference/
#You are given two positive integer arrays nums1 and nums2, both of length n.
#The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).
#You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.
#Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.
#|x| is defined as:
#x if x >= 0, or
#-x if x < 0.


class Solution(object):
    def minAbsoluteSumDiff(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """       
        from bisect import bisect_left
        diff = [abs(a - b) for a, b in zip(nums1, nums2)]
        max_diff = max(diff)
        if max_diff == 0:
            return 0
        nums1.sort()
        result = sum(diff) - max_diff
        for i, d in enumerate(diff):
            if d == max_diff:
                j = bisect_left(nums1, nums2[i])
                if j < len(nums1):
                    result += nums1[j] - nums2[i]
                if j > 0:
                    result += nums2[i] - nums1[j - 1]
        return result % (10 ** 9 + 7)
        

    