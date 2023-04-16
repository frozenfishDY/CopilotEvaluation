#https://leetcode.com/problems/maximum-erasure-value/
#You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
#Return the maximum score you can get by erasing exactly one subarray.
#An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).


class Solution(object):
    def maximumUniqueSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)+1):
                if len(set(nums[i:j]))==len(nums[i:j]):
                    result=max(result,sum(nums[i:j]))
        return result
        

    