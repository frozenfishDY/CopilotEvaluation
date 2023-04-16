#https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
#Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
#Return the length of the shortest subarray to remove.
#A subarray is a contiguous subsequence of the array.


class Solution(object):
    def findLengthOfShortestSubarray(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        if len(arr)==1:
            return 0
        if len(arr)==2:
            if arr[0]<=arr[1]:
                return 0
            else:
                return 1
        arr.sort()
        arr.append(None)
        count=1
        for i in range(1,len(arr)):
            if arr[i]==arr[i-1]+1:
                count+=1
            else:
                if count==len(arr)-1:
                    return 0
                count=1
        return len(arr)-1-count
        

    