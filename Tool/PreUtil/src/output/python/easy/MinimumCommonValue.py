#https://leetcode.com/problems/minimum-common-value/
#Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
#Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.


class Solution(object):
    def getCommon(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """ 
        if len(nums1)==0 or len(nums2)==0:
            return -1
        i=0
        j=0
        while i<len(nums1) and j<len(nums2):
            if nums1[i]==nums2[j]:
                return nums1[i]
            elif nums1[i]<nums2[j]:
                i+=1
            else:
                j+=1
        return -1

    