#https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
#You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
#The length of the subarray is k, and
#All the elements of the subarray are distinct.
#Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
#A subarray is a contiguous non-empty sequence of elements within an array.


class Solution(object):
    def maximumSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k==1:
            return max(nums)
        if k==len(nums):
            return sum(set(nums))
        nums.sort()
        nums.append(None)
        count=1
        for i in range(1,len(nums)):
            if nums[i]==nums[i-1]+1:
                count+=1
            else:
                if count==len(nums)-1:
                    return sum(nums)-nums[0]
                count=1
        return sum(nums)-nums[0]-nums[1]
        

    