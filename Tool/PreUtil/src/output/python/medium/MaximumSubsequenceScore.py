#https://leetcode.com/problems/maximum-subsequence-score/
#You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
#For chosen indices i0, i1, ..., ik - 1, your score is defined as:
#The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
#It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
#Return the maximum possible score.
#A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.


class Solution(object):
    def maxScore(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """ 
        res = 0
        for i in range(k+1):
            if i <= len(nums1) and k-i <= len(nums2):
                res = max(res,sum(sorted(nums1)[-i:])*min(sorted(nums2)[:k-i]))
        return res
            
          
        

    