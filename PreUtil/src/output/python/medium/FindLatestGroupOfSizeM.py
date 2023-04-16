#https://leetcode.com/problems/find-latest-group-of-size-m/
#Given an array arr that represents a permutation of numbers from 1 to n.
#You have a binary string of size n that initially has all its bits set to zero. At each step i (assuming both the binary string and arr are 1-indexed) from 1 to n, the bit at position arr[i] is set to 1.
#You are also given an integer m. Find the latest step at which there exists a group of ones of length m. A group of ones is a contiguous substring of 1's such that it cannot be extended in either direction.
#Return the latest step at which there exists a group of ones of length exactly m. If no such group exists, return -1.


class Solution(object):
    def findLatestStep(self, arr, m):
        """
        :type arr: List[int]
        :type m: int
        :rtype: int
        """
        if m==len(arr):
            return m
        if m==1:
            return len(arr)
        if m==0:
            return -1
        arr.sort()
        arr.append(None)
        count=1
        for i in range(1,len(arr)):
            if arr[i]==arr[i-1]+1:
                count+=1
            else:
                if count==m:
                    return len(arr)-i
                count=1
        return -1
        

    