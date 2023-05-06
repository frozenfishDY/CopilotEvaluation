#https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
#On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
#A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
#Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.


class Solution(object):
    def removeStones(self, stones):
        """
        :type stones: List[List[int]]
        :rtype: int
        """      
        n = len(stones)
        uf = UnionFind(n)
        for i in range(n):
            for j in range(i+1,n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    uf.union(i,j)
        return n - uf.count

        

    