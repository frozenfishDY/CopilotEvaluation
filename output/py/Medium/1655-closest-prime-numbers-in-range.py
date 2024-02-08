#https://leetcode.com/problems/closest-prime-numbers-in-range/
#Given two positive integers left and right, find the two integers num1 and num2 such that:
#left <= nums1 < nums2 <= right .
#nums1 and nums2 are both prime numbers.
#nums2 - nums1 is the minimum amongst all other pairs satisfying the above conditions.
#Return the positive integer array ans = [nums1, nums2]. If there are multiple pairs satisfying these conditions, return the one with the minimum nums1 value or [-1, -1] if such numbers do not exist.
#A number greater than 1 is called prime if it is only divisible by 1 and itself.


class Solution(object):
    def closestPrimes(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """  
        def isPrime(n):
            if n == 1:
                return False
            for i in range(2, int(n ** 0.5) + 1):
                if n % i == 0:
                    return False
            return True
        
        res = []
        for i in range(left, right + 1):
            if isPrime(i):
                res.append(i)
        if len(res) < 2:
            return [-1, -1]
        min_diff = float('inf')
        min_pair = []
        for i in range(len(res) - 1):
            if res[i + 1] - res[i] < min_diff:
                min_diff = res[i + 1] - res[i]
                min_pair = [res[i], res[i + 1]]
        return min_pair

        

    