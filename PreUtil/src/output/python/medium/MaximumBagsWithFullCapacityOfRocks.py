#https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
#You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.
#Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.


class Solution(object):
    def maximumBags(self, capacity, rocks, additionalRocks):
        """
        :type capacity: List[int]
        :type rocks: List[int]
        :type additionalRocks: int
        :rtype: int
        """ 
        # 1. find the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
        # 2. return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
        # 1. find the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
        # 2. return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
        return self.maximumBagsFromIndex(capacity, rocks, additionalRocks, 0, 0)

        
    