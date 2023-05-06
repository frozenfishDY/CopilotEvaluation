#https://leetcode.com/problems/two-city-scheduling/
#A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
#Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.


class Solution(object):
    def twoCitySchedCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        costs.sort(key=lambda x:x[0]-x[1])
        res = 0
        for i in range(len(costs)//2):
            res += costs[i][0] + costs[len(costs)-i-1][1]
        return res
        

    