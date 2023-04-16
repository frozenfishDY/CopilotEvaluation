#https://leetcode.com/problems/minimum-cost-to-merge-stones/
#There are n piles of stones arranged in a row. The ith pile has stones[i] stones.
#A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.
#Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.


class Solution(object):
    def mergeStones(self, stones, k):
        """
        :type stones: List[int]
        :type k: int
        :rtype: int
        """
        if not stones:
            return 0
        if len(stones)==1:
            return 0
        if len(stones)==2:
            return 0
        result = 0
        for i in range(len(stones)):
            result += self.mergeStones(stones[:i]+stones[i+1:],k)
        return result
        
        
    