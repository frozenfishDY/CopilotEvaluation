#https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
#Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.
#In case of a tie, return the minimum such integer.
#Notice that the answer is not neccesarilly a number from arr.


class Solution(object):
    def findBestValue(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        arr.sort()
        n = len(arr)
        prefix = [0]*(n+1)
        for i in range(n):
            prefix[i+1] = prefix[i]+arr[i]
        res = 0
        diff = target
        for i in range(n):
            if arr[i]*(n-i) >= target:
                res = (target-prefix[i])/(n-i)
                diff = target - prefix[i] - res*(n-i)
                break
        for i in range(res+1):
            if abs(target-prefix[n]-i*(n)) < diff:
                res = i
                diff = abs(target-prefix[n]-i*(n))
        return res
        

    