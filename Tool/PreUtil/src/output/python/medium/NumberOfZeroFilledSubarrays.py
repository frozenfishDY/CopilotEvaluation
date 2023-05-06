#https://leetcode.com/problems/number-of-zero-filled-subarrays/
#Given an integer array nums, return the number of subarrays filled with 0.
#A subarray is a contiguous non-empty sequence of elements within an array.


class Solution(object):
    def zeroFilledSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=0
        for i in range(len(nums)):
            if nums[i]==0:
                result+=1
                for j in range(i+1,len(nums)):
                    if nums[j]==0:
                        result+=1
                    else:
                        break
        return result
        
    