#https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
#You are given an integer array arr.
#We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
#Return the largest number of chunks we can make to sort the array.


class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        if not arr:
            return 0
        if len(arr)==1:
            return 1
        result = 0
        for i in range(len(arr)):
            if max(arr[:i+1])<=min(arr[i+1:]):
                result+=1
        return result
        
        
    