#https://leetcode.com/problems/intervals-between-identical-elements/
#You are given a 0-indexed array of n integers arr.
#The interval between two elements in arr is defined as the absolute difference between their indices. More formally, the interval between arr[i] and arr[j] is |i - j|.
#Return an array intervals of length n where intervals[i] is the sum of intervals between arr[i] and each element in arr with the same value as arr[i].
#Note: |x| is the absolute value of x.


class Solution(object):
    def getDistances(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        result=[]
        for i in range(len(arr)):
            result.append(sum([abs(i-j) for j in range(len(arr)) if arr[i]==arr[j]]))
        return result
        

    