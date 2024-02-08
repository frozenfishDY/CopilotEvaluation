#https://leetcode.com/problems/verbal-arithmetic-puzzle/
#Given an equation, represented by words on the left side and the result on the right side.
#You need to check if the equation is solvable under the following rules:
#Each character is decoded as one digit (0 - 9).
#No two characters can map to the same digit.
#Each words[i] and result are decoded as one number without leading zeros.
#Sum of numbers on the left side (words) will equal to the number on the right side (result).
#Return true if the equation is solvable, otherwise return false.


class Solution(object):
    def isSolvable(self, words, result):
        """
        :type words: List[str]
        :type result: str
        :rtype: bool
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

        
        
        
    