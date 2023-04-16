#https://leetcode.com/problems/sum-of-subarray-minimums/
#Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.


class Solution(object):
    def sumSubarrayMins(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """       
        res = 0
        for i in range(len(arr)):
            for j in range(i, len(arr)):
                res += min(arr[i:j+1])
        return res % (10**9 + 7)

        

    