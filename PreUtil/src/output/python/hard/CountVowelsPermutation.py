#https://leetcode.com/problems/count-vowels-permutation/
#Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
#Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
#Each vowel 'a' may only be followed by an 'e'.
#Each vowel 'e' may only be followed by an 'a' or an 'i'.
#Each vowel 'i' may not be followed by another 'i'.
#Each vowel 'o' may only be followed by an 'i' or a 'u'.
#Each vowel 'u' may only be followed by an 'a'.
#Since the answer may be too large, return it modulo 10^9 + 7.


class Solution(object):
    def countVowelPermutation(self, n):
        """
        :type n: int
        :rtype: int
        """      
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
                res += 5 * get_permutations_without_repetitions(5, i-1)
            used = set()
            for i in range(k):
                for j in range(1 if i else 1, n[i]):
                    if j not in used:
                        res += get_permutations_without_repetitions(5-i, k-i-1)
                if n[i] in used:
                    break
                used.add(n[i])
            else:
                res += 1
            return res
        
        return get_count_without_repetitions(get_digits(n))

        
        
        
    