#https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
#You are given an integer array bloomDay, an integer m and an integer k.
#You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
#The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
#Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.


class Solution(object):
    def minDays(self, bloomDay, m, k):
        """
        :type bloomDay: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        # 1. If the number of flowers is less than the number of bouquets times the number of flowers in a bouquet, then return -1
        # 2. Get the minimum and maximum bloom days
        # 3. Loop through the bloom days
        # 4. If the number of bouquets is greater than or equal to m, then return the current bloom day
        # 5. Return -1
        if len(bloomDay) < m * k:
            return -1
        min_bloom_day = min(bloomDay)
        max_bloom_day = max(bloomDay)
        for i in range(min_bloom_day, max_bloom_day + 1):
            bouquets = 0
            flowers = 0
            for j in range(len(bloomDay)):
                if bloomDay[j] <= i:
                    flowers += 1
                    if flowers == k:
                        bouquets += 1
                        flowers = 0
                else:
                    flowers = 0
            if bouquets >= m:
                return i
        return -1
        

    