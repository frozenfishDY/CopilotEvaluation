#https://leetcode.com/problems/longest-mountain-in-array/
#You may recall that an array arr is a mountain array if and only if:
#arr.length >= 3
#There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
#arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
#arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
#Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.


class Solution(object):
    def longestMountain(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        if len(arr) < 3:
            return 0
        res = 0
        i = 1
        while i < len(arr) - 1:
            if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:
                left = i - 1
                right = i + 1
                while left > 0 and arr[left] > arr[left - 1]:
                    left -= 1
                while right < len(arr) - 1 and arr[right] > arr[right + 1]:
                    right += 1
                res = max(res, right - left + 1)
                i = right
            i += 1
        return res
        

    