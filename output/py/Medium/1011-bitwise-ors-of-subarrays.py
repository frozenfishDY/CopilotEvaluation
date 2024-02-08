#https://leetcode.com/problems/bitwise-ors-of-subarrays/
#Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
#The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
#A subarray is a contiguous non-empty sequence of elements within an array.


class Solution(object):
    def subarrayBitwiseORs(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        res = set()
        cur = set()
        for a in arr:
            cur = {a | b for b in cur} | {a}
            res |= cur
        return len(res)
        

    