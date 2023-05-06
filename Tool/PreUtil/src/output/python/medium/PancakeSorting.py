#https://leetcode.com/problems/pancake-sorting/
#Given an array of integers arr, sort the array by performing a series of pancake flips.
#In one pancake flip we do the following steps:
#Choose an integer k where 1 <= k <= arr.length.
#Reverse the sub-array arr[0...k-1] (0-indexed).
#For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.
#Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.


class Solution(object):
    def pancakeSort(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """       
        res = []
        for i in range(len(arr), 1, -1):
            j = arr.index(i)
            arr[:j+1] = arr[:j+1][::-1]
            res.append(j+1)
            arr[:i] = arr[:i][::-1]
            res.append(i)
        return res

        

    