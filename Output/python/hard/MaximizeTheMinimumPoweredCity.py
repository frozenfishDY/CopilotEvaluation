#https://leetcode.com/problems/maximize-the-minimum-powered-city/
#You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.
#Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.
#Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.
#The power of a city is the total number of power stations it is being provided power from.
#The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.
#Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.
#Note that you can build the k power stations in multiple cities.


class Solution(object):
    def maxPower(self, stations, r, k):
        """
        :type stations: List[int]
        :type r: int
        :type k: int
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

        
        
        
    