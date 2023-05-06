#https://leetcode.com/problems/flower-planting-with-no-adjacent/
#You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.
#All gardens have at most 3 paths coming into or leaving it.
#Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
#Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.


class Solution(object):
    def gardenNoAdj(self, n, paths):
        """
        :type n: int
        :type paths: List[List[int]]
        :rtype: List[int]
        """
        res = [0] * n
        graph = [[] for _ in range(n)]
        for x, y in paths:
            graph[x - 1].append(y - 1)
            graph[y - 1].append(x - 1)
        for i in range(n):
            res[i] = ({1, 2, 3, 4} - {res[j] for j in graph[i]}).pop()
        return res
        

    