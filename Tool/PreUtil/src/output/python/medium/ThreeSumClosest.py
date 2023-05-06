#https://leetcode.com/problems/3sum-closest/
#Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
#Return the sum of the three integers.
#You may assume that each input would have exactly one solution.


class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        res = nums[0]+nums[1]+nums[2]
        for i in range(len(nums)-2):
            l,r = i+1,len(nums)-1
            while l<r:
                s = nums[i]+nums[l]+nums[r]
                if abs(s-target)<abs(res-target):
                    res = s
                if s == target:
                    return res
                elif s<target:
                    l+=1
                else:
                    r-=1
        return res
        

    