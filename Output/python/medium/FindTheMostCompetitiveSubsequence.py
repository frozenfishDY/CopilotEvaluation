#https://leetcode.com/problems/find-the-most-competitive-subsequence/
#Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
#An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
#We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.


class Solution(object):
    def mostCompetitive(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k==1:
            return [min(nums)]
        if k==len(nums):
            return nums
        nums.append(None)
        count=1
        for i in range(1,len(nums)):
            if nums[i]==nums[i-1]:
                count+=1
            else:
                if count==k:
                    return nums[i-k:i]
                count=1
        return nums[len(nums)-k-1:len(nums)-1]
        

    