#https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
#You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).
#Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 10^9 + 7.


class Solution(object):
    def numWays(self, steps, arrLen):
        """
        :type steps: int
        :type arrLen: int
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
            
      