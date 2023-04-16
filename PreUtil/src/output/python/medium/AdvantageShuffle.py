#https://leetcode.com/problems/advantage-shuffle/
#You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
#Return any permutation of nums1 that maximizes its advantage with respect to nums2.


class Solution(object):
    def advantageCount(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort()
        res = []
        for num in nums2:
            i = 0
            while i < len(nums1) and nums1[i] <= num:
                i += 1
            if i == len(nums1):
                res.append(nums1.pop(0))
            else:
                res.append(nums1.pop(i))
        return res
        

    