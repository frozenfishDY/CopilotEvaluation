#https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/
#Given an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.
#A subarray is a contiguous non-empty sequence of elements within an array.
#The greatest common divisor of an array is the largest integer that evenly divides all the array elements.


class Solution(object):
    def subarrayGCD(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result=0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)+1):
                if len(set([nums[k]+c for k in range(i,j) for c in range(k+1)]))==len([nums[k]+c for k in range(i,j) for c in range(k+1)]):
                    result=max(result,min(nums[i:j]))
        return result


        
    