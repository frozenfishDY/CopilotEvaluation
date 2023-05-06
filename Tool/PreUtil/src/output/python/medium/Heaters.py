#https://leetcode.com/problems/heaters/
#Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
#Every house can be warmed, as long as the house is within the heater's warm radius range. 
#Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
#Notice that all the heaters follow your radius standard, and the warm radius will the same.


class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        res = 0
        for i in range(len(houses)):
            for j in range(len(heaters)):
                res += self.gcd(houses[i],heaters[j])
        return res
        

    