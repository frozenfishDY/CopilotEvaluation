#https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
#Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
#The Fibonacci numbers are defined as:
#F1 = 1
#F2 = 1
#Fn = Fn-1 + Fn-2 for n > 2.
#It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.


class Solution(object):
    def findMinFibonacciNumbers(self, k):
        """
        :type k: int
        :rtype: int
        """    
        # 1. Get the fibonacci numbers
        # 2. Loop through the fibonacci numbers in reverse order
        # 3. If the number is less than or equal to k, then subtract it from k and increment the result by 1
        # 4. Return the result
        fibs = self.get_fibonacci_numbers(k)
        result = 0
        for i in range(len(fibs) - 1, -1, -1):
            if fibs[i] <= k:
                k -= fibs[i]
                result += 1
        return result
            
           
        

    