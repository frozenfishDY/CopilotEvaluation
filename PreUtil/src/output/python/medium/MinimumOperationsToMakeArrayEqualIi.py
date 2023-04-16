#https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/
#You are given two integer arrays nums1 and nums2 of equal length n and an integer k. You can perform the following operation on nums1:
#Choose two indexes i and j and increment nums1[i] by k and decrement nums1[j] by k. In other words, nums1[i] = nums1[i] + k and nums1[j] = nums1[j] - k.
#nums1 is said to be equal to nums2 if for all indices i such that 0 <= i < n, nums1[i] == nums2[i].
#Return the minimum number of operations required to make nums1 equal to nums2. If it is impossible to make them equal, return -1.


class Solution(object):
    def minOperations(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """       
        if k > len(nums1) + len(nums2):
            return -1
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        nums1.sort()
        nums2.sort()
        res = float('inf')
        for i in range(k + 1):
            j = k - i
            if i > len(nums1) or j > len(nums2):
                continue
            if i == 0:
                res = min(res, nums2[j - 1] - nums2[0])
            elif j == 0:
                res = min(res, nums1[-1] - nums1[-i])
            else:
                res = min(res, nums2[j - 1] - nums2[0], nums1[-1] - nums1[-i], nums1[-1] - nums2[0], nums2[j - 1] - nums1[0])
        return res

        

    