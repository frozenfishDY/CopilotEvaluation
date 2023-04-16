#https://leetcode.com/problems/split-array-with-same-average/
#You are given an integer array nums.
#You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
#Return true if it is possible to achieve that and false otherwise.
#Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.


class Solution(object):
    def splitArraySameAverage(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        # 1. find the average of the array
        # 2. find the number of elements in each array
        # 3. find the sum of each array
        # 4. find the average of each array
        # 5. return the result
        return self.find_average(nums)
        
        
    