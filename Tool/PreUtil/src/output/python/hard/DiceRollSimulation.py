#https://leetcode.com/problems/dice-roll-simulation/
#A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
#Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls. Since the answer may be too large, return it modulo 109 + 7.
#Two sequences are considered different if at least one element differs from each other


class Solution(object):
    def dieSimulator(self, n, rollMax):
        """
        :type n: int
        :type rollMax: List[int]
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

        
        
        
    