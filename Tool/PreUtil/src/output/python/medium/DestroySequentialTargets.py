#https://leetcode.com/problems/destroy-sequential-targets/
#You are given a 0-indexed array nums consisting of positive integers, representing targets on a number line. You are also given an integer space.
#You have a machine which can destroy targets. Seeding the machine with some nums[i] allows it to destroy all targets with values that can be represented as nums[i] + c * space, where c is any non-negative integer. You want to destroy the maximum number of targets in nums.
#Return the minimum value of nums[i] you can seed the machine with to destroy the maximum number of targets.


class Solution(object):
    def destroyTargets(self, nums, space):
        """
        :type nums: List[int]
        :type space: int
        :rtype: int
        """
        result=0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)+1):
                if len(set([nums[k]+c*space for k in range(i,j) for c in range(1000)]))==len([nums[k]+c*space for k in range(i,j) for c in range(1000)]):
                    result=max(result,min(nums[i:j]))
        return result
        

    