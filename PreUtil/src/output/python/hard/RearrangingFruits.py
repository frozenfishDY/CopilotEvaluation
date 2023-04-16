#https://leetcode.com/problems/rearranging-fruits/
#You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:
#Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
#The cost of the swap is min(basket1[i],basket2[j]).
#Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.
#Return the minimum cost to make both the baskets equal or -1 if impossible.


class Solution(object):
    def minCost(self, basket1, basket2):
        """
        :type basket1: List[int]
        :type basket2: List[int]
        :rtype: int
        """       
        if not basket1 or not basket2:
            return 0
        if len(basket1) != len(basket2):
            return -1
        basket1.sort()
        basket2.sort()
        cost = 0
        for i in range(len(basket1)):
            cost += min(basket1[i],basket2[i])
        return cost
        
        
    