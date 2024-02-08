#https://leetcode.com/problems/numbers-with-repeated-digits/
#Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.


class Solution(object):
    def numDupDigitsAtMostN(self, n):
        """
        :type n: int
        :rtype: int
        """       
        def get_digits(n):
            res = []
            while n:
                res.append(n % 10)
                n /= 10
            return res[::-1]
        
        def get_permutations(n, k):
            res = 1
            for i in range(n, n-k, -1):
                res *= i
            return res
        
        def get_permutations_without_repetitions(n, k):
            res = 1
            for i in range(n, n-k, -1):
                res *= i
            for i in range(1, k+1):
                res /= i
            return res
        
        def get_count_without_repetitions(n):
            res = 0
            k = len(n)
            for i in range(1, k):
                res += 9 * get_permutations_without_repetitions(9, i-1)
            used = set()
            for i in range(k):
                for j in range(1 if i else 1, n[i]):
                    if j not in used:
                        res += get_permutations_without_repetitions(9-i, k-i-1)
                if n[i] in used:
                    break
                used.add(n[i])
            else:
                res += 1
            return res
        
        return n - get_count_without_repetitions(get_digits(n))


            
       