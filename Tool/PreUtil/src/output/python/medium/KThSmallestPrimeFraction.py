#https://leetcode.com/problems/k-th-smallest-prime-fraction/
#You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
#For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
#Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].


class Solution(object):
    def kthSmallestPrimeFraction(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """      
        return sorted([arr[i]/arr[j] for i in range(len(arr)) for j in range(len(arr))])[k-1]

        

    