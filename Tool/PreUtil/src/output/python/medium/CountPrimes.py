#https://leetcode.com/problems/count-primes/
#Given an integer n, return the number of prime numbers that are strictly less than n.


class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """       
        if n < 3:
            return 0
        isPrime = [True] * n
        isPrime[0] = isPrime[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if isPrime[i]:
                isPrime[i * i: n: i] = [False] * len(isPrime[i * i: n: i])
        return sum(isPrime)

        

    