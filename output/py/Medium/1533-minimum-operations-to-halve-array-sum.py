#https://leetcode.com/problems/minimum-operations-to-halve-array-sum/
#You are given an array nums of positive integers. In one operation, you can choose any number from nums and reduce it to exactly half the number. (Note that you may choose this reduced number in future operations.)
#Return the minimum number of operations to reduce the sum of nums by at least half.


class Solution(object):
    def halveArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=0
        while sum(nums)>sum(nums)/2:
            nums[nums.index(max(nums))]=max(nums)/2
            result+=1
        return result
        

    