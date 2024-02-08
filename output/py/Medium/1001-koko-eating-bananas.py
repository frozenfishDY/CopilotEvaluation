#https://leetcode.com/problems/koko-eating-bananas/
#Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
#Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
#Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
#Return the minimum integer k such that she can eat all the bananas within h hours.


class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        l, r = 1, max(piles)
        while l < r:
            m = (l + r) // 2
            if sum((p - 1) // m + 1 for p in piles) > h:
                l = m + 1
            else:
                r = m
        return l
        

    