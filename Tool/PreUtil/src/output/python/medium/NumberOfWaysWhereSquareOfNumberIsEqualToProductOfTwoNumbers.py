#https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/
#Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:
#Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
#Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.


class Solution(object):
    def numTriplets(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """       
        count=0
        for i in range(len(nums1)):
            for j in range(len(nums2)-1):
                for k in range(j+1,len(nums2)):
                    if nums1[i]*nums1[i]==nums2[j]*nums2[k]:
                        count+=1
        for i in range(len(nums2)):
            for j in range(len(nums1)-1):
                for k in range(j+1,len(nums1)):
                    if nums2[i]*nums2[i]==nums1[j]*nums1[k]:
                        count+=1
        return count

        

    