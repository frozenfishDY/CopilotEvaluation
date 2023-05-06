#https://leetcode.com/problems/median-of-two-sorted-arrays/
#Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
#The overall run time complexity should be O(log (m+n)).


class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """       
        nums1.extend(nums2)
        nums1.sort()
        if len(nums1)%2==0:
            return (nums1[len(nums1)//2]+nums1[len(nums1)//2-1])/2
        else:
            return nums1[len(nums1)//2]

        
    