#https://leetcode.com/problems/create-maximum-number/
#You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
#Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
#Return an array of the k digits representing the answer.


class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums1:
            return nums2[:k]
        if not nums2:
            return nums1[:k]
        if k==0:
            return []
        if k==len(nums1)+len(nums2):
            return sorted(nums1+nums2,reverse=True)
        result=[]
        for i in range(k+1):
            if i<=len(nums1) and k-i<=len(nums2):
                result.append(self.merge(self.maxArray(nums1,i),self.maxArray(nums2,k-i)))
        return max(result)
        
        
    