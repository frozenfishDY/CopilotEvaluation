#https://leetcode.com/problems/next-greater-element-i/
#The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
#You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
#For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
#Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.


class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res=[]
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                if nums1[i]==nums2[j]:
                    for k in range(j+1,len(nums2)):
                        if nums2[k]>nums2[j]:
                            res.append(nums2[k])
                            break
                    else:
                        res.append(-1)
        return res

    