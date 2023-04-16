#https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
#You are given a 0-indexed array of distinct integers nums.
#There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
#A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
#Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.


class Solution(object):
    def minimumDeletions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return min([nums.index(min(nums))+len(nums)-nums[::-1].index(max(nums))-1,len(nums)-nums.index(min(nums))-nums[::-1].index(max(nums))-1])
        

    